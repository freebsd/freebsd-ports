# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberchef
PORTVERSION=	8.24.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
DISTFILES=	cyberchef.htm CyberChef.js
EXTRACT_ONLY=

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Cyber operations within a web browser

LICENSE=	APACHE20

USE_GITHUB=	nodefault
GH_ACCOUNT=	gchq
GH_PROJECT=	CyberChef

NO_BUILD=       yes
NO_ARCH=        yes

do-install:
	${MKDIR}                            ${STAGEDIR}${WWWDIR}
	${INSTALL} ${DISTDIR}/cyberchef.htm ${STAGEDIR}${WWWDIR}/
	${INSTALL} ${DISTDIR}/CyberChef.js  ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
