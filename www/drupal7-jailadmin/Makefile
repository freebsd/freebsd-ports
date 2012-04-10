# Ports collection makefile for:	drupal7-jailadmin
# Date created:				01 Mar 2012
# Whom:					Shawn Webb <bsdports@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	jailadmin
DISTVERSION=	7.x-0.2
CATEGORIES=	www
MASTER_SITES=	http://0xfeedface.org/~shawn/freebsd/ports/distfiles/

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Drupal 7 module for administering FreeBSD vnet jails

LICENSE=	BSD

USE_DRUPAL=	yes

.include <bsd.port.options.mk>

DRUPAL_MODULE=	yes
DRUPAL_VERSION=	7
MODULE_FILES=	README \
				jailadmin.admin.inc \
				jailadmin.helpers.inc \
				jailadmin.info \
				jailadmin.install \
				jailadmin.module \
				jailconfig.inc \
				jailstatus.inc \
				classes/Jail.php \
				classes/Mount.php \
				classes/Network.php \
				classes/NetworkDevice.php \
				classes/Service.php

MODULE_DIRS=	classes

DOC_FILES=	README

.include <bsd.port.mk>
