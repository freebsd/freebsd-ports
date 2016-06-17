# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	google_analytics
DISTVERSION=	6.x-3.5
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds the Google Analytics web stats tracking system to your website

DEPRECATED=	www/drupal6 upstream is EOL and port expired 2016-04-24
EXPIRATION_DATE=	2016-04-24

USES=		drupal:6,module

MODULE_FILES=	googleanalytics.admin.inc googleanalytics.install googleanalytics.module \
		googleanalytics.info googleanalytics.js googleanalytics.test

DOC_FILES=	LICENSE.txt README.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
