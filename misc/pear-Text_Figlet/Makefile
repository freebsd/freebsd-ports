# Ports collection makefile for:  pear-Text_Figlet
# Date created:			  15 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Text_Figlet
PORTVERSION=	0.8.0
CATEGORIES=	misc pear

MAINTAINER=	antonio@php.net
COMMENT=	Render text using FIGlet fonts

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

CATEGORY=	Text
FILES=		Figlet.php
DOCS=		README.TXT
EXAMPLES=	3-d.flf alligator2.flf bell.flf block.flf contessa.flf cybermedium.flf \
		isometric1.flf larry3d.flf script.flf slant.flf figlet.php
_EXAMPLESDIR=	docs/examples

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/docs ${WRKSRC}/
	${MV} ${WRKDIR}/Figlet.php ${WRKSRC}/

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 404
IGNORE=		"You need PHP 4.0.4 or later to install PEAR::Text_Figlet"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
