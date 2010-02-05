# New ports collection makefile for:	drupal5-google_analytics
# Date created:				31 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	google_analytics
DISTVERSION=	5.x-1.9
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Adds the Google Analytics web statistics tracking system to your website.

DRUPAL5_MODULE=	yes
MODULE_FILES=	googleanalytics.info googleanalytics.install googleanalytics.js \
		googleanalytics.module po/ca.po po/de.po po/es.po po/fr.po \
		po/it.po po/googleanalytics.pot po/ja.po po/pl.po po/pt.po \
		po/ru.po po/sk.po
MODULE_DIRS=	po

DOC_FILES=	LICENSE.txt README.txt UPGRADE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
