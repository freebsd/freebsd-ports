# New ports collection makefile for:	drupal-attachment
# Date created:				31 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	attachment
DISTVERSION=	${DRUPAL_VERSION}
PORTREVISION=	20060928
CATEGORIES=	www security

MAINTAINER=	nick@foobar.org
COMMENT=	An alternative to Drupal's included upload module

RUN_DEPENDS+=	${LOCALBASE}/${DRUPAL_MODDIR}/filemanager.module:${PORTSDIR}/www/drupal4-filemanager

DRUPAL_MODULE=	yes
MODULE_FILES=	attachment.install attachment.module
DOC_FILES=	LICENSE.txt README.txt CREDITS INSTALL

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
