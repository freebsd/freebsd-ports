# Created by: Nick Hilliard <nick@netability.ie>
# $FreeBSD$

PORTNAME=	nodewords
DISTVERSION=	6.x-1.14
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal module which allows the end-user to set meta tags for nodes

USES=		drupal:6,module
MODULE_DIRS=	nodewords_basic nodewords_extra includes nodewords_og
MODULE_FILES=	includes/forum.inc includes/image.inc includes/node.inc \
		includes/taxonomy.inc includes/taxonomy_menu.inc includes/uc_catalog.inc \
		includes/user.inc nodewords.admin.inc nodewords.api.php \
		nodewords.info nodewords.install nodewords.module \
		nodewords.test nodewords_basic/nodewords_basic.info \
		nodewords_basic/nodewords_basic.install \
		nodewords_basic/nodewords_basic.module \
		nodewords_extra/nodewords_extra.info \
		nodewords_extra/nodewords_extra.install \
		nodewords_extra/nodewords_extra.module \
		nodewords_og/nodewords_og.info \
		nodewords_og/nodewords_og.install \
		nodewords_og/nodewords_og.module
DOC_FILES=	README.txt CHANGELOG.txt API.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
