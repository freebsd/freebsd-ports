# New ports collection makefile for:	drupal-gsitemap
# Date created:				27 Jan 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	gsitemap
DISTVERSION=	4.7.x-1.0
PORTREVISION=	20070111
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Produces Google/sitemaps.org compliant XML WWW site maps

DRUPAL_MODULE=	yes
MODULE_FILES=	gsitemap.install gsitemap.module
DOC_FILES=	INSTALL.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
