# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	nice_menus
DISTVERSION=	6.x-2.1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CSS / JavaScript pull-down menus for Drupal

USES=		drupal:6,module

MODULE_DIRS=	superfish/js superfish translations
MODULE_FILES=	arrow-right.png nice_menus.install nice_menus_default-rtl.css \
		arrow-down.png nice_menus.css nice_menus.js nice_menus_default.css \
		arrow-left.png nice_menus.info nice_menus.module screenshot-drupal.org.png \
		translations/nice_menus.pot translations/de.po translations/sv.po \
		superfish/js/jquery.bgiframe.min.js \
		superfish/js/jquery.hoverIntent.minified.js \
		superfish/js/superfish.js
DOC_FILES=	CHANGELOG.txt README.txt UPGRADE.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
