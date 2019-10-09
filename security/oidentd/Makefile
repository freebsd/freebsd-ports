# Created by: trevor
# $FreeBSD$

PORTNAME=	oidentd
PORTVERSION=	2.3.2
CATEGORIES=	security
MASTER_SITES=	https://github.com/janikrabe/oidentd/releases/download/v2.3.2/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ident server that supports user-defined ident strings

LICENSE=	GPLv2

USES=		bison
USE_RC_SUBR=	oidentd
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/oidentd etc/oidentd.conf.sample \
		etc/oidentd_masq.conf.sample
MANPAGES=	oidentd.conf.5 oidentd_masq.conf.5 oidentd.8
.for man in ${MANPAGES}
PLIST_FILES+=	man/man${man:E}/${man}.gz
.endfor
USE_CSTD=	gnu89

OPTIONS_DEFINE=	IPV6

CONFIGURE_ARGS=--disable-masq

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${PREFIX}&,g' ${WRKSRC}/src/oidentd.h
	@${REINPLACE_CMD} -e 's|\[5-9\]||g;s|\[4-9\]||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oidentd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/oidentd.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/oidentd_masq.conf.sample ${STAGEDIR}${PREFIX}/etc
.for MANFILE in ${MANPAGES}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/doc/${MANFILE}
	${INSTALL_MAN} ${WRKSRC}/doc/${MANFILE} ${STAGEDIR}${PREFIX}/man/man${MANFILE:E}
.endfor

.include <bsd.port.mk>
