# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	page_title
DISTVERSION=	6.x-2.7
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal module to provide fine-grained control of page titles

RUN_DEPENDS=	drupal6-token>=0:www/drupal6-token

USES=		drupal:6,module
MODULE_FILES=	page_title-admin-settings-form.tpl.php page_title.install page_title.views.inc \
		views_handler_field_node_page_title.inc page_title.admin.css page_title.js \
		page_title.views_default.inc page_title.admin.inc page_title.legacy.inc \
		page_title.info page_title.module modules/blog.page_title.inc modules/forum.page_title.inc \
		modules/page_title.page_title.inc modules/comment.page_title.inc \
		modules/node.page_title.inc modules/taxonomy.page_title.inc \
		modules/user.page_title.inc views/plugins/page_title_plugin_display_page_with_page_title.inc \
		tests/page_title.test tests/page_title_views_test.info tests/page_title_views_test.module \
		tests/page_title_views_test.test tests/page_title_views_test.views_default.inc
MODULE_DIRS=	modules views/plugins/ views tests

DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
