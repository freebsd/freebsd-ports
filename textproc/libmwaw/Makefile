# $FreeBSD$

PORTNAME=	libmwaw
PORTVERSION=	0.2.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Import library for some old mac text documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include

EXTRA_PATCHES+=	${FILESDIR}/0001-use-correct-type.patch:-p1

GNU_CONFIGURE=	yes
USES=		compiler:features libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
CONFIGURE_ARGS+=	--with-sharedptr=c++11
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
CONFIGURE_ARGS+=	--with-sharedptr=boost
EXTRA_PATCHES+=	${FILESDIR}/0001-std-isfinite-is-C-11.patch:-p1
.endif

.include <bsd.port.post.mk>
