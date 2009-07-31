# New ports collection makefile for:	pbi-thumbnailer
# Date created:				08 June 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pbi-thumbnailer
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	http://www.marcuscom.com/pbi-thumbnailer/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generates icon thumbnails for PC-BSD installer files

USE_BZIP2=	yes
USE_GNOME=	gtk20 gconf2
MAKE_ENV=	GCONF_CONFIG_SOURCE=${GCONF_CONFIG_SOURCE}

GCONF_SCHEMAS=	pbi-thumbnail.schemas

.include <bsd.port.mk>
