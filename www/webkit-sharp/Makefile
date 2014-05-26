# $FreeBSD$

PORTNAME=	webkit-sharp
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BROKEN=		does not fetch

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB+=	ASSEMBLY_VERSION=1.1.15

GNU_CONFIGURE=	yes
USES=		gmake mono pathfix pkgconfig tar:bzip2
USE_GNOME=	gtksharp20

.include <bsd.port.mk>
