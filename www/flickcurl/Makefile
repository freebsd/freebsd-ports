# New ports collection makefile for:	flickcurl
# Date created:				2007-07-27
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	flickcurl
PORTVERSION=	0.12
CATEGORIES=	www
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for the Flickr API

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gnometarget ltverhack libxml2 pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
