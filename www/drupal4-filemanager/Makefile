# New ports collection makefile for:	drupal-filemanager
# Date created:				31 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	filemanager
DISTVERSION=	${DRUPAL_VERSION}
PORTREVISION=	20060915
CATEGORIES=	www security

MAINTAINER=	nick@foobar.org
COMMENT=	A full featured file management API for Drupal modules

DEPRECATED=	Drupal 4.7.x is end-of-life since 200802.  Please migrate to Drupal 6.x
EXPIRATION_DATE=	2009-03-26 

DRUPAL4_MODULE=	yes
MODULE_FILES=	filemanager.install filemanager.module
DOC_DIRS=	doc
DOC_FILES=	LICENSE.txt README.txt CREDITS INSTALL doc/filemanager.php

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
