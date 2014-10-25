# $FreeBSD$

PORTNAME=	coppermine
PORTVERSION=	1.5.34
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Coppermine/1.5.x/
DISTNAME=	cpg${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Web picture gallery script

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS IMAGEMAGICK
IMAGEMAGICK_DESC=	Use ImageMagick instead of PHP GD extension

IMAGEMAGICK_RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	mysql pcre ctype
USES=		zip

NO_BUILD=	yes
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

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}/

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${RM} ${DOCFILES}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
