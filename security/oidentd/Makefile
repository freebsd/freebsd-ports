# New ports collection makefile for:	oidentd
# Date created:		29 Mar 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	oidentd
PORTVERSION=	2.0.8
PORTREVISION=	1
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

OPTIONS=	IPV6 "Enable IPv6 support"		on \
		MASQ "Enable NAT/IP masq support"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.else
CATEGORIES+=   ipv6
.endif

.if defined(WITHOUT_MASQ) || ${OSVERSION} >= 800000
CONFIGURE_ARGS+=--disable-masq
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${PREFIX}&,g' ${WRKSRC}/src/oidentd.h

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
