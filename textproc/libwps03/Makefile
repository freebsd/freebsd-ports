# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwps
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	03

MAINTAINER=	office@FreeBSD.org
COMMENT=	Microsoft file word processor format import filter library

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL20=	${WRKSRC}/COPYING.MPL

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		compiler:features libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
CONFIGURE_ARGS+=	--with-sharedptr=c++11
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
CONFIGURE_ARGS+=	--with-sharedptr=boost
.endif

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.post.mk>
