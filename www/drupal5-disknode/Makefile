# New ports collection makefile for:	drupal5-disknode
# Date created:				25 Jul 2007
# Whom:					Geoff Glasson <g_glasson@jimali.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	disknode
DISTVERSION=	5.x-1.x-dev
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DRUPAL}

MAINTAINER=	g_glasson@jimali.dyndns.org
COMMENT=	File download module

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po
MODULE_FILES=	po/disknode-module.pot disknode.browse.tpl.inc disknode.inc \
		disknode.info disknode.info.tpl.inc disknode.install disknode.js \
		disknode.mkdir.tpl.inc disknode.module disknode.rmdir.tpl.inc \
		disknode.style.css disknode.upload.tpl.inc
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
