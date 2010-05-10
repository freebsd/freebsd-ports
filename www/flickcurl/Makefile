# New ports collection makefile for:	flickcurl
# Date created:				2007-07-27
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	flickcurl
PORTVERSION=	1.18
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for the Flickr API

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gnometarget ltverhack libxml2 pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc

MAN1=		flickrdf.1 flickcurl.1 flickcurl-config.1

.include <bsd.port.mk>
