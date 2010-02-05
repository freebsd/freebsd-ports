# New ports collection makefile for:	drupal5-bookreview
# Date created:				25 Jul 2007
# Whom:					Geoff Glasson <g_glasson@jimali.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	bookreview
DISTVERSION=	5.x-1.x-dev
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	g_glasson@jimali.dyndns.org
COMMENT=	The book review module allows a site to publish book reviews.

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po
MODULE_FILES=	bookreview.info bookreview.install bookreview.module bookreview.css \
		po/ja.po

DOC_FILES=	LICENSE.txt README.txt CHANGELOG INSTALL

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
