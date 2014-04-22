# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pbi-thumbnailer
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	x11-fm gnome
MASTER_SITES=	http://www.marcuscom.com/pbi-thumbnailer/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generates icon thumbnails for PC-BSD installer files

USES=		pkgconfig tar:bzip2 uidfix shared-mime-info
USE_GNOME=	gtk20 gconf2
MAKE_ENV=	GCONF_CONFIG_SOURCE=${GCONF_CONFIG_SOURCE} UPDATE_MIME_DATABASE=${TRUE}

GCONF_SCHEMAS=	pbi-thumbnail.schemas

.include <bsd.port.mk>
