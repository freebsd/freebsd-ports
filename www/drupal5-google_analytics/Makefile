# New ports collection makefile for:	drupal5-google_analytics
# Date created:				31 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	google_analytics
DISTVERSION=	5.x-1.6
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Adds the Google Analytics web statistics tracking system to your website.

DRUPAL5_MODULE=	yes
MODULE_FILES=	googleanalytics.info googleanalytics.install googleanalytics.js \
		googleanalytics.module
DOC_FILES=	LICENSE.txt README.txt UPGRADE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
