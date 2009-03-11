# New ports collection makefile for:	drupal5-simplenews
# Date created:			17 Jul 2008
# Whom:				Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	tagadelic
DISTVERSION=	6.x-1.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Tagadelic module for Drupal 6

DRUPAL6_MODULE=	yes
MODULE_DIRS=	translations
MODULE_FILES=	tagadelic.css tagadelic.info tagadelic.install \
		tagadelic.module \
		translations/zh-hans.po translations/de.po \
		translations/es.po translations/fr.po \
		translations/gl.po translations/he.po \
		translations/hu.po translations/ja.po \
		translations/nl.po translations/pl.po \
		translations/ru.po translations/tagadelic.pot
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
