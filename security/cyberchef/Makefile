# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberchef
PORTVERSION=	8.24.2
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	security
DISTFILES=	cyberchef.htm
EXTRACT_ONLY=	# none

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Cyber operations within a web browser

LICENSE=	APACHE20

MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_TAGNAME}/
USE_GITHUB=	nodefault
GH_ACCOUNT=	gchq
GH_PROJECT=	CyberChef

NO_BUILD=       yes
NO_ARCH=        yes

do-install:
	${MKDIR}                            ${STAGEDIR}${WWWDIR}
	${INSTALL} ${DISTDIR}/cyberchef.htm ${STAGEDIR}${WWWDIR}/index.html

.include <bsd.port.mk>
