# New ports collection makefile for:	drupal5-gsitemap
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	gsitemap
DISTVERSION=	5.x-1.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Produces Google/sitemaps.org compliant XML WWW site maps

DRUPAL5_MODULE=	yes
MODULE_FILES=	gsitemap.info gsitemap.install gsitemap.module gss.xsl
DOC_FILES=	INSTALL.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
