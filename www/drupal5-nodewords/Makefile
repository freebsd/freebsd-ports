# New ports collection makefile for:	drupal5-nodewords
# Date created:				08 Nov 2008
# Whom:					Nick Hilliard <nick@netability.ie>
#
# $FreeBSD$
#

PORTNAME=	nodewords
DISTVERSION=	5.x-1.13
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	A drupal module which allows the end-user to set meta tags for nodes

DRUPAL5_MODULE=	yes
MODULE_DIRS=	metatags
MODULE_FILES=	metatags/DC.Title.inc metatags/Revisit-After.inc \
		metatags/abstract.inc metatags/copyright.inc \
		metatags/description.inc metatags/geourl.inc \
		metatags/keywords.inc metatags/robots.inc nodewords.info \
		nodewords.install nodewords.module

DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
