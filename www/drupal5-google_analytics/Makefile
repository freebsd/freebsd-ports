# New ports collection makefile for:	drupal5-google_analytics
# Date created:				31 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	google_analytics
DISTVERSION=	5.x-1.0
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Adds the Google Analytics web statistics tracking system to your website.

DRUPAL5_MODULE=	yes
MODULE_FILES=	googleanalytics.info googleanalytics.install googleanalytics.module
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
