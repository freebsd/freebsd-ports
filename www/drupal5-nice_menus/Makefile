# New ports collection makefile for:	drupal5-nice_menus
# Date created:				20 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	nice_menus
DISTVERSION=	5.x-1.4
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	CSS / Javascript pull-down menus for Drupal

DRUPAL5_MODULE=	yes

MODULE_FILES=	po/ja.po po/nice_menus.pot arrow-down.png arrow-left.png \
		arrow-right.png nice_menus.css nice_menus.info nice_menus.js \
		nice_menus.module nice_menus_default.css \
		screenshot-drupal.org.png
MODULE_DIRS=	po

DOC_FILES=	CHANGELOG.txt README.txt UPGRADE.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
