# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlwrapp
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern style C++ library for working with XML data

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	XSLT
XSLT_DESC=	Build libxsltwrap library (requires libxslt)

USE_GNOME=	gnomehack libxml2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXSLT}
USE_GNOME+=	libxslt
PLIST_SUB+=	XSLT=""
.else
CONFIGURE_ARGS+=--disable-xslt
PLIST_SUB+=	XSLT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif
.include <bsd.port.mk>
