# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	gecko-sharp
PORTVERSION=	0.13
PORTREVISION=	9
PKGNAMESUFFIX=	20
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.novell.com/pub/mono/sources/${PORTNAME}2/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings to embed Mozilla

BROKEN=		Does not compile against recent mono
DEPRECATED=	Broken, no upstream found and no release in 8 years
EXPIRATION_DATE=2016-11-27

USE_GNOME=	gtksharp20
USES=		gmake mono pathfix pkgconfig gecko tar:bzip2
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
