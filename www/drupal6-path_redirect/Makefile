# New ports collection makefile for:	drupal6-path_redirect
# Date created:				February 24, 2010
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	path_redirect
DISTVERSION=	6.x-1.0-beta6
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Drupal module to allow redirects

DRUPAL6_MODULE=	yes

MODULE_FILES=	generate/path_redirect_generate.drush.inc \
		generate/path_redirect_generate.info \
		generate/path_redirect_generate.module \
		path_redirect.admin.inc path_redirect.info \
		path_redirect.install path_redirect.js path_redirect.module \
		path_redirect.test

MODULE_DIRS=	generate

DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
