# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$

PORTNAME=	libgnomecups
PORTVERSION=	0.2.3
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Support library for gnome cups administration

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups-client

USES=		pkgconfig gettext gmake
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack ltverhack glib20
USE_LDCONFIG=	yes
USE_AUTOTOOLS=  libtool
CPPFLAGS+=	-I${LOCALBASE}/include -D_IPP_PRIVATE_STRUCTURES
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
