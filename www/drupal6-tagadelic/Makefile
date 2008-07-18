# New ports collection makefile for:	drupal5-simplenews
# Date created:			17 Jul 2008
# Whom:				Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	tagadelic
DISTVERSION=	5.x-1.0
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Tagadelic module for Drupal 5

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po
MODULE_FILES=	tagadelic.info tagadelic.css tagadelic.module \
		po/tagadelic.pot \
		po/de.po po/es.po po/he.po po/hu.po po/ja.po \
		po/nl.po po/ru.po
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
