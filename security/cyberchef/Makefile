# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberchef
PORTVERSION=	9.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_TAGNAME}/
DISTNAME=	CyberChef_${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Cyber operations within a web browser

LICENSE=	APACHE20

USES=		zip

USE_GITHUB=	nodefault
GH_ACCOUNT=	gchq
GH_PROJECT=	CyberChef

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL} ${WRKDIR}/${DISTNAME}.html ${STAGEDIR}${WWWDIR}/index.html
	${CP} -R ${WRKDIR}/images ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKDIR}/modules ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKDIR}/assets ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
