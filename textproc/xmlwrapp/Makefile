# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlwrapp
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern style C++ library for working with XML data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	XSLT DOCS
XSLT_DESC=	Build libxsltwrap library (requires libxslt)
OPTIONS_SUB=	yes

XSLT_USE=	gnome=libxslt
XSLT_CONFIGURE_ENABLE=	xslt

USES=		pathfix pkgconfig
USE_GNOME=	libxml2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

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
