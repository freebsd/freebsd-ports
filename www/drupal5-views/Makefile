# New ports collection makefile for:	drupal5-views
# Date created:				25 Jul 2007
# Whom:					Geoff Glasson <g_glasson@jimali.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	views
DISTVERSION=	5.x-1.7
CATEGORIES=	www

MAINTAINER=	g_glasson@jimali.dyndns.org
COMMENT=	Controls how content lists are generated

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po modules
MODULE_FILES=	go-bottom.png go-down.png go-top.png go-up.png user-trash.png \
		views.info views.install views.module views_cache.inc views_query.inc views_rss.info \
		views_rss.module views_theme_wizard.info views_theme_wizard.module views_ui.css \
		views_ui.info views_ui.module modules/views_book.inc modules/views_comment.inc \
		modules/views_forum.inc modules/views_node.inc modules/views_profile.inc \
		modules/views_search.inc modules/views_statistics.inc modules/views_taxonomy.inc \
		modules/views_upload.inc modules/views_user.inc po/da.po po/de.po po/el.po po/es.po \
		po/fr.po po/hu.po po/nl.po po/pl.po po/sv.po po/views.pot
DOC_FILES=	LICENSE.txt README.txt CHANGELOG.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
