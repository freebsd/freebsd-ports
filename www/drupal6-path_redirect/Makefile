# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	path_redirect
DISTVERSION=	6.x-1.0-rc2
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal module to allow redirects

DEPRECATED=	www/drupal6 upstream is EOL and port expired 2016-04-24
EXPIRATION_DATE=	2016-04-24

USES=		drupal:6,module

MODULE_FILES=	generate/path_redirect_generate.drush.inc \
		generate/path_redirect_generate.info \
		generate/path_redirect_generate.module \
		path_redirect.admin.inc path_redirect.info \
		path_redirect.install path_redirect.js path_redirect.module \
		path_redirect.test

MODULE_DIRS=	generate

DOC_FILES=	LICENSE.txt README.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
