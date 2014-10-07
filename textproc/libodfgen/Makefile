# $FreeBSD$

PORTNAME=	libodfgen
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/libwpd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for generating documents in Open Document Format (ODF)

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libetonyek-0.0.so:${PORTSDIR}/graphics/libetonyek \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		compiler:features libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
CONFIGURE_ARGS+=	--with-sharedptr=c++11
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
CONFIGURE_ARGS+=	--with-sharedptr=boost
.endif

.include <bsd.port.post.mk>
