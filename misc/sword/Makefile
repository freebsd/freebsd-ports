# Created by: Willem van Engen <wvengen@stack.nl>
# $FreeBSD$

PORTNAME=	sword
PORTVERSION=	1.7.4
PORTREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v${PORTVERSION:R}/ \
		http://crosswire.org/ftpmirror/pub/sword/source/v${PORTVERSION:R}/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Framework for manipulating Bible texts

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:devel/cppunit

# Workaround for for FreeBSD_11+.
BUILD_DEPENDS+= clang38:lang/clang38
CC=		clang38
CXX=		clang++38

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-conf --with-zlib
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	CURL CLUCENE
CLUCENE_DESC=	Include indexing capability
OPTIONS_DEFAULT=CURL CLUCENE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS=	libcurl.so:ftp/curl
CONFIGURE_ARGS+=	--with-curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MCLUCENE}
USES+=		compiler:c++11-lib
USE_CXXSTD=	gnu++11
LIB_DEPENDS+=	libclucene-core.so:textproc/clucene \
		libicudata.so:devel/icu
CONFIGURE_ARGS+=	--with-clucene=${LOCALBASE} --with-icu
.else
CONFIGURE_ARGS+=	--without-clucene --without-icu
.endif

post-patch:
	@${REINPLACE_CMD} 's|-O3||' ${WRKSRC}/configure

post-install:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install_config)
	${MV} ${STAGEDIR}${PREFIX}/etc/sword.conf \
		${STAGEDIR}${PREFIX}/etc/sword.conf.sample

.include <bsd.port.mk>
