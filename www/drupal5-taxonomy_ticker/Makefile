# New ports collection makefile for:	drupal5-taxonomy_ticker
# Date created:				15 Jun 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	taxonomy_ticker
DISTVERSION=	5.x-1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Drupal module to provide scrolling ticker for content

DRUPAL5_MODULE=	yes

MODULE_FILES=	taxonomy_ticker.css taxonomy_ticker.info \
		taxonomy_ticker.install taxonomy_ticker.js \
		taxonomy_ticker.module taxonomy_ticker_horizontally.css \
		taxonomy_ticker_horizontally.js

DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
