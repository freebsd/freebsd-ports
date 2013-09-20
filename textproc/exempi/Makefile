# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/exempi/Makefile,v 1.1 2008/02/26 18:50:26 ahze Exp $

PORTNAME=	exempi
PORTVERSION=	2.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A port of Adobe XMP SDK to work on UNIX

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack
CONFIGURE_ARGS=	--enable-unittest=no
CONFIGURE_ENV=	LIBS="${ICONV_LIB}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		pathfix iconv
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
