# New ports collection makefile for:	webkit-sharp
# Date created:		2008-09-01
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	webkit-sharp
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB+=	ASSEMBLY_VERSION=1.1.15

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtksharp20

.include <bsd.port.mk>
