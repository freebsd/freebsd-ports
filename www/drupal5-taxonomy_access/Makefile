# New ports collection makefile for:	drupal5-taxonomy_access
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	taxonomy_access
DISTVERSION=	5.x-1.1
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Access control system for the Drupal based on Taxonomy classification

DRUPAL5_MODULE=	yes
MODULE_FILES=	admin.css taxonomy_access.info taxonomy_access.install \
		taxonomy_access.module taxonomy_access_admin.inc
DOC_FILES=	INSTALL.txt LICENSE.txt README.txt UPDATE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
