# New ports collection makefile for:	drupal6-nice_menus
# Date created:				20 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	nice_menus
DISTVERSION=	6.x-1.3
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	CSS / JavaScript pull-down menus for Drupal

USE_DRUPAL=	yes
DRUPAL6_MODULE=	yes

MODULE_DIRS=	po translations
MODULE_FILES=	po/ja.po po/nice_menus.pot arrow-down.png arrow-left.png \
		arrow-right.png nice_menus.css nice_menus.info \
		nice_menus.install nice_menus.js nice_menus.module \
		nice_menus_default.css screenshot-drupal.org.png \
		translations/nice_menus.pot translations/sk.po \
		translations/sv.po

DOC_FILES=	CHANGELOG.txt README.txt UPGRADE.txt LICENSE.txt

.include <bsd.port.mk>
