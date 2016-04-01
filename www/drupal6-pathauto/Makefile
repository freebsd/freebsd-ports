# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	pathauto
DISTVERSION=	6.x-2.0
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically generates URLs for Drupal content

RUN_DEPENDS=	drupal6-token>=0:www/drupal6-token

USES=		drupal:6,module
MODULE_FILES=	pathauto.admin.inc pathauto.inc pathauto.install pathauto.module \
		pathauto.test pathauto.api.php pathauto.info pathauto.js \
		pathauto.pathauto.inc pathauto.tokens.inc
DOC_FILES=	INSTALL.txt API.txt README.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
