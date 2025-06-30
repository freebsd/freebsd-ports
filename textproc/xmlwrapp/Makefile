PORTNAME=	xmlwrapp
PORTVERSION=	0.7.0
PORTREVISION=	32
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern style C++ library for working with XML data
WWW=		https://xmlwrapp.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

OPTIONS_DEFINE=	XSLT DOCS
XSLT_DESC=	Build libxsltwrap library (requires libxslt)
OPTIONS_SUB=	yes

XSLT_USE=	gnome=libxslt
XSLT_CONFIGURE_ENABLE=	xslt

USES=		compiler:c++11-lang gnome libtool localbase:ldflags pathfix \
		pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

LDFLAGS+=	-lboost_system

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} '/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in

post-install:
	@(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
