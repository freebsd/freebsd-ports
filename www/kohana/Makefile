# $FreeBSD$

PORTNAME=	kohana
PORTVERSION=	3.3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Elegant HMVC PHP5 framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		php zip

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} "s,'system','${WWWDIR}/system', ; \
		s,'modules','${WWWDIR}/modules'," ${WRKSRC}/index.php

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "application example.htaccess \
		index.php install.php modules system" ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
