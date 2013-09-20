# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	tagadelic
DISTVERSION=	6.x-1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Tagadelic module for Drupal 6

USE_DRUPAL=	yes
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

NO_STAGE=	yes
.include <bsd.port.mk>
