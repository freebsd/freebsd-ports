# Created by: Patrick Bihan-Faou <patrick@mindstep.com>
# $FreeBSD$

PORTNAME=	pipsecd
PORTVERSION=	19991014
PORTREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	http://www.komquats.com/distfiles/ \
		LOCAL/cy
DISTNAME=	pipsec-19991014

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Simple IPSEC tunnel tool from Pierre Beyssac

USES+=		ssl

ALL_TARGET=	pipsecd

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipsecd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/pipsecd.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	# ${CHMOD} 755 ${STAGEDIR}${PREFIX}/etc/rc.d/pipsecd.sh;
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ipsec
	${INSTALL_DATA} ${WRKSRC}/pipsecd.conf.sample ${STAGEDIR}${PREFIX}/etc/ipsec
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/pipsecd
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/pipsecd
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${STAGEDIR}${PREFIX}/share/doc/pipsecd
	${INSTALL_DATA} ${WRKSRC}/README.port ${STAGEDIR}${PREFIX}/share/doc/pipsecd

.include <bsd.port.mk>
