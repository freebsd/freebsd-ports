# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwps
PORTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Microsoft file word processor format import filter library

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		libtool pkgconfig pathfix compiler:features
USE_LDCONFIG=	yes
PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
CONFIGURE_ARGS=	--with-sharedptr=c++11
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
CONFIGURE_ARGS=	--with-sharedptr=boost
.endif

.include <bsd.port.post.mk>
