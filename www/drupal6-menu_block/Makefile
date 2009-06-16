# New ports collection makefile for:	drupal6-menu_block
# Date created:				2 May 2009
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	menu_block
DISTVERSION=	6.x-2.2
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Drupal module to provide configurable menu tree blocks

DRUPAL6_MODULE=	yes
MODULE_FILES=	translations/menu_block.pot menu-block-admin.css \
		menu-block-wrapper.tpl.php menu-block.js \
		menu_block.admin.inc menu_block.book.inc \
		menu_block.follow.inc menu_block.info menu_block.install \
		menu_block.module menu_block.pages.inc menu_block.sort.inc
MODULE_DIRS=	translations

DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
