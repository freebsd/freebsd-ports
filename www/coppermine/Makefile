# $FreeBSD$

PORTNAME=	coppermine
PORTVERSION=	1.5.24
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Coppermine/1.5.x/
DISTNAME=	cpg${PORTVERSION}

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	A web picture gallery script

OPTIONS_DEFINE=	DOCS IMAGEMAGICK
IMAGEMAGICK_DESC=	Use ImageMagick instead of PHP GD extension

USE_PHP=	mysql pcre ctype
USE_ZIP=	yes

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/cpg${PORTVERSION:R:R}${PORTVERSION:R:E}x
DOCFILES=	CHANGELOG.txt COPYING.txt README.txt

SUB_FILES+=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
	cd ${WRKSRC}/ && ${RM} ${DOCFILES}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
