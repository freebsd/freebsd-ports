# New ports collection makefile for:	drupal6-google_analytics
# Date created:				31 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	google_analytics
DISTVERSION=	6.x-2.2
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Adds the Google Analytics web stats tracking system to your website

DRUPAL6_MODULE=	yes

MODULE_FILES=	tests/googleanalytics_basic.test googleanalytics.admin.inc \
		googleanalytics.info googleanalytics.install \
		googleanalytics.js googleanalytics.module translations/de.po \
		translations/el.po translations/fr.po translations/ja.po \
		translations/googleanalytics.pot translations/pl.po \
		translations/sk.po

MODULE_DIRS=	tests translations

DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
