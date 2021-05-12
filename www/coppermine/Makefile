PORTNAME=	coppermine
PORTVERSION=	1.6.12
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web picture gallery script

LICENSE=	GPLv3

USES=		php

OPTIONS_DEFINE=	DOCS IMAGEMAGICK
IMAGEMAGICK_DESC=	Use ImageMagick instead of PHP GD extension

IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick6
IMAGEMAGICK_USE_OFF=	PHP=gd

USE_PHP=	ctype hash json mysqli pcre xml

USE_GITHUB=	yes
GH_ACCOUNT=	coppermine-gallery
GH_PROJECT=	cpg1.6.x

NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	CHANGELOG.txt LICENSE.txt README.txt

SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "By default, coppermine depends on PHP with GD support."
	@${ECHO_MSG} "You may select IMAGEMAGICK to depend on ImageMagick instead of GD."
	@${ECHO_MSG} ""

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install:
	cd ${WRKSRC}/ && ${RM} ${PORTDOCS}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
