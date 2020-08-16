# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwps
PORTVERSION=	0.4.11
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Microsoft file word processor format import filter library

LICENSE=	LGPL21+ MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL20=	${WRKSRC}/COPYING.MPL

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

LIBVERSION=	4.0.11
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

.include <bsd.port.mk>
