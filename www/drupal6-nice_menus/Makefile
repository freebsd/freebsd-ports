# New ports collection makefile for:	drupal6-nice_menus
# Date created:				20 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	nice_menus
DISTVERSION=	6.x-1.1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	CSS / Javascript pull-down menus for Drupal

DRUPAL6_MODULE=	yes

MODULE_FILES=	arrow-down.png arrow-left.png arrow-right.png \
		nice_menus.css nice_menus.info nice_menus.js \
		nice_menus.module nice_menus_default.css

DOC_FILES=	CHANGELOG.txt README.txt UPGRADE.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
