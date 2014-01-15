# Created by: Willem van Engen <wvengen@stack.nl>
# $FreeBSD$

PORTNAME=	sword
PORTVERSION=	1.7.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v${PORTVERSION:R}/ \
		http://crosswire.org/ftpmirror/pub/sword/source/v${PORTVERSION:R}/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Framework for manipulating Bible texts

LICENSE=	GPLv2

CONFLICTS=	sword-1.6.*
PKGNAMESUFFIX=	17

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit

USES=		gmake pkgconfig
USE_AUTOTOOLS=	automake autoconf
CONFIGURE_ARGS=	--with-conf --with-zlib
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	CURL CLUCENE
CLUCENE_DESC=	Include indexing capability
OPTIONS_DEFAULT=CURL CLUCENE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MCLUCENE}
LIB_DEPENDS+=	libclucene-core.so:${PORTSDIR}/textproc/clucene \
		libicudata.so:${PORTSDIR}/devel/icu
CONFIGURE_ARGS+=	--with-clucene=${LOCALBASE} --with-icu
.else
CONFIGURE_ARGS+=	--without-clucene --without-icu
.endif

run-autotools::	run-autotools-aclocal

	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/configure

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e's|-O3||g' \
		-e 's|%%DESTDIR%%|${STAGEDIR}|g' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/sword/mods.d
.if !exists(${PREFIX}/etc/sword.conf)
	@(cd ${WRKSRC} && ${GMAKE} install_config)
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
