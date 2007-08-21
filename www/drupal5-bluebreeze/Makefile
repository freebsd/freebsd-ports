# New ports collection makefile for:	drupal5-bluebreeze
# Date created:				25 Jul 2007
# Whom:					Geoff Glasson <g_glasson@jimali.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	bluebreeze
DISTVERSION=	5.x-1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DRUPAL}

MAINTAINER=	g_glasson@jimali.dyndns.org
COMMENT=	The bluebreeze theme wants to combine style with good usability

DRUPAL5_THEME=	yes
MODULE_DIRS=	bluebreeze-fixed images
MODULE_FILES=	block.tpl.php box.tpl.php comment.tpl.php favicon.ico layout.css logo.png \
		node.tpl.php page.tpl.php screenshot-drupal.org.jpg screenshot-drupal.org.png \
		screenshot.png style.css template.php \
		bluebreeze-fixed/logo.png bluebreeze-fixed/screenshot-drupal.org.jpg \
		bluebreeze-fixed/screenshot.png bluebreeze-fixed/style.css \
		images/bg-footer.gif images/bg-header.gif images/bg-mission.gif images/bg-poll.gif \
		images/bg-primary-hover.gif images/bg-primary.gif images/bg-secondary.gif \
		images/bg-thead.gif images/crystal-run.gif images/crystal-search.gif \
		images/icon-alert.png images/icon-info.png images/menu-collapsed.gif \
		images/menu-expanded.gif images/menu-leaf.gif images/mini-attachment.png \
		images/mini-category.png images/mini-comment.png images/mini-edit.png \
		images/mini-readmore.png images/mini-trash.png images/mini-user-light-blue.png \
		images/progressbar.gif

DOC_FILES=	LICENSE.txt CHANGELOG.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
