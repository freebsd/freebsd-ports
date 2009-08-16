# New ports collection makefile for: drupal5-securepages
# Date created:		04 Januari 2008
# Whom:			Dennis Cabooter <freebsd@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	securepages
DISTVERSION=	5.x-1.6
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set which pages are always going to be used in secure mode (SSL)

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po
MODULE_FILES=	securepages.install securepages.module securepages.info

DOC_FILES=	LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
