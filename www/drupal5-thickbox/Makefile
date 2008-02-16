# New ports collection makefile for:  drupal5-thickbox
# Date created:  11 February 2008
# Whom:          Jeremy Iverson <jeremy@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	thickbox
DISTVERSION=	5.x-1.1
CATEGORIES=		www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	jeremy@algenta.com
COMMENT=	Thickbox module for Drupal 5

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po
MODULE_FILES=	loading_animation.gif thickbox_auto.js thickbox_login.js \
		thickbox.css thickbox.info thickbox.install thickbox.js \
		thickbox.module \
		po/ja.po po/nl.po po/thickbox.pot
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
