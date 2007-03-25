# New ports collection makefile for:	drupal-taxonomy_access
# Date created:				26 Jan 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	taxonomy_access
DISTVERSION=	4.7.x-1.x-dev
PORTREVISION=	20070205
PORTEPOCH=	2
CATEGORIES=	www security
MASTER_SITE_SUBDIR=	pav/drupal

MAINTAINER=	nick@foobar.org
COMMENT=	Access control system for the Drupal based on Taxonomy classification

DRUPAL_MODULE=	yes
MODULE_FILES=	taxonomy_access.install taxonomy_access.module taxonomy_access_admin.inc
DOC_FILES=	INSTALL.txt LICENSE.txt README.txt UPDATE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
