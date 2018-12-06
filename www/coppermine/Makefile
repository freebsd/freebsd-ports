# $FreeBSD$

PORTNAME=	coppermine
PORTVERSION=	1.5.46
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Coppermine/1.5.x/
DISTNAME=	cpg${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Web picture gallery script

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv3

IGNORE_WITH_PHP=	71 72 73

OPTIONS_DEFINE=	DOCS IMAGEMAGICK
IMAGEMAGICK_DESC=	Use ImageMagick instead of PHP GD extension

IMAGEMAGICK_RUN_DEPENDS+=	convert:graphics/ImageMagick6

USE_PHP=	mysql pcre ctype
USES=		php zip

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/cpg${PORTVERSION:R:R}${PORTVERSION:R:E}x
DOCFILES=	CHANGELOG.txt COPYING.txt README.txt

SUB_FILES+=	pkg-message

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIMAGEMAGICK)
USE_PHP+=	gd
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "By default, coppermine depends on PHP with GD support."
	@${ECHO_MSG} "You may select IMAGEMAGICK to depend on ImageMagick instead of GD."
	@${ECHO_MSG} ""

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR}

do-install:
	cd ${WRKSRC}/ && ${RM} ${DOCFILES}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
