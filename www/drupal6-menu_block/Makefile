# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	menu_block
DISTVERSION=	6.x-2.4
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal module to provide configurable menu tree blocks

USES=		drupal:6,module
MODULE_FILES=	menu-block-wrapper.tpl.php menu_block.admin.inc menu_block.book.inc menu_block.info \
		menu_block.module menu_block.sort.inc menu-block-admin.css menu-block.js menu_block.api.php \
		menu_block.follow.inc menu_block.install menu_block.pages.inc \
		plugins/content_types/menu_tree/icon_contrib_booknavigation.png \
		plugins/content_types/menu_tree/icon_contrib_menu.png \
		plugins/content_types/menu_tree/icon_contrib_navigation.png \
		plugins/content_types/menu_tree/icon_contrib_primarylinks.png  \
		plugins/content_types/menu_tree/menu_tree.inc
MODULE_DIRS=	plugins/content_types/menu_tree plugins/content_types plugins
DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
