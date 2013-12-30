# Created by: trevor
# $FreeBSD$

PORTNAME=	oidentd
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/ojnk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ident server that supports user-defined ident strings

USE_RC_SUBR=	oidentd
GNU_CONFIGURE=	yes

MAN5=		oidentd.conf.5 oidentd_masq.conf.5
MAN8=		oidentd.8
PLIST_FILES=	sbin/oidentd etc/oidentd.conf.sample \
		etc/oidentd_masq.conf.sample
USE_CSTD=	gnu89

OPTIONS_DEFINE=	IPV6 MASQ
OPTIONS_DEFAULT=	MASQ
MASQ_DESC=	Enable NAT/IP masq support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--disable-ipv6
.else
CATEGORIES+=	ipv6
.endif

.if ! ${PORT_OPTIONS:MMASQ} || ${OSVERSION} >= 800000
CONFIGURE_ARGS+=--disable-masq
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${PREFIX}&,g' ${WRKSRC}/src/oidentd.h
	@${REINPLACE_CMD} -e 's|\[5-9\]||g;s|\[4-9\]||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oidentd ${PREFIX}/sbin
	${INSTALL_DATA} ${MAN5:S,^,${FILESDIR}/,:S,5$,sample,} ${PREFIX}/etc
.if !defined(NO_INSTALL_MANPAGES)
.for MANFILE in ${MAN5} ${MAN8}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/doc/${MANFILE}
.endfor
	${INSTALL_MAN} ${MAN5:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man5
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man8
.endif

.include <bsd.port.post.mk>
