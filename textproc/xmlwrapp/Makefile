# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlwrapp
PORTVERSION=	0.7.0
PORTREVISION=	19
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern style C++ library for working with XML data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to configure: invalid value: boost_major_version=

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

OPTIONS_DEFINE=	XSLT DOCS
XSLT_DESC=	Build libxsltwrap library (requires libxslt)
OPTIONS_SUB=	yes

XSLT_USE=	gnome=libxslt
XSLT_CONFIGURE_ENABLE=	xslt

USES=		compiler:c++11-lang gnome libtool pathfix pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} '/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in

post-install:
	@(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
