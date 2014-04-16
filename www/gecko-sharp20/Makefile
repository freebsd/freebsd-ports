# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	gecko-sharp
PORTVERSION=	0.13
PORTREVISION=	8
PKGNAMESUFFIX=	20
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.novell.com/pub/mono/sources/${PORTNAME}2/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings to embed Mozilla

USE_GNOME=	gtksharp20
USES=		gmake pathfix pkgconfig gecko tar:bzip2
GNU_CONFIGURE=	yes

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
