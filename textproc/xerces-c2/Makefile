# Created by: Bjoern A. Zeeb <bz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xerces-c2
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	xerces-c/source
DISTNAME=	xerces-c-src_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

OPTIONS_DEFINE=		DOCS DEBUG EXAMPLES THREADS
OPTIONS_SINGLE=		TCODER
OPTIONS_SINGLE_TCODER=	ICONVFBSD ICU NATIVE
OPTIONS_DEFAULT=	ICONVFBSD THREADS
ICONVFBSD_DESC=		Use IconvFBSD transcoder
ICU_DESC=		Use ICU transcoder
NATIVE_DESC=		Use native transcoder

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICU}
LIB_DEPENDS+=		libicuuc.so:${PORTSDIR}/devel/icu
ICUROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		ICUROOT=${ICUROOT}
MAKE_ENV+=		ICUROOT=${ICUROOT}
TRANSCODER=		icu
PLIST_SUB+=		TRANSICONV="@comment "
PLIST_SUB+=		TRANSICU=""
.endif

.if ${PORT_OPTIONS:MNATIVE}
TRANSCODER=		native
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.endif

.if ${PORT_OPTIONS:MICONVFBSD}
USES+=			iconv
TRANSCODER=		IconvFBSD
ICONVROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		ICONVROOT=${ICONVROOT}
MAKE_ENV+=		ICONVROOT=${ICONVROOT}
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.endif

USE_LDCONFIG=	yes

XERCESWRKSRC=		${WRKSRC}/src/xercesc
CONFIGURE_WRKSRC=	${XERCESWRKSRC}
BUILD_WRKSRC=		${XERCESWRKSRC}
INSTALL_WRKSRC=		${XERCESWRKSRC}

USE_GMAKE=		yes
MAKE_ENV+=		XERCESCROOT=${WRKSRC}
MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		XERCESCROOT=${WRKSRC} TRANSCODER=${TRANSCODER}
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} -n socket -P ${PREFIX}

CONFIGURE_ARGS+=	-t ${TRANSCODER}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	-d
.endif

.if defined(ARCH) && \
	(${ARCH} == "alpha" || ${ARCH} == "sparc64" || \
	${ARCH} == "amd64" || ${ARCH} == "ia64")
# set bitsToBuild to 64
CONFIGURE_ARGS+=	-b 64
SAMPLES_CONFIG_ARGS+=	-b 64
.endif

.if ! ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	-r none
.else
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif

XERCESC_LIB_VERSION=	${PORTVERSION:S/.//:R}
XERCESC_LIB=		libxerces-c.so.${PORTVERSION:S/.//}
XERCESC_DEPDOM_LIB=	libxerces-depdom.so.${PORTVERSION:S/.//}
PLIST_SUB+=		XERCESC_LIB=${XERCESC_LIB} \
			XERCESC_DEPDOM_LIB=${XERCESC_DEPDOM_LIB} \
			XERCESC_LIB_VERSION=${XERCESC_LIB_VERSION}

.if ${PORT_OPTIONS:MEXAMPLES}
ALL_TARGET?=	all samples
XERCES_BINS?=	CreateDOMDocument DOMCount DOMPrint EnumVal MemParse PParse \
		PSVIWriter Redirect SAX2Count SAX2Print SAXCount SAXPrint \
		SCMPrint SEnumVal StdInParse
SAMPLES_CONFIG_ARGS+=	-p freebsd -c ${CC} -x ${CXX}
.if ! ${PORT_OPTIONS:MTHREADS}
SAMPLES_CONFIG_ARGS+=	-r none
.else
SAMPLES_CONFIG_ARGS+=	-r pthread
SAMPLES_CONFIG_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#CP = -cp -p#CP = -cp#'	\
		${WRKSRC}/src/xercesc/Makefile.incl
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|-liconv|${ICONV_LIB}|' \
		${WRKSRC}/src/xercesc/Makefile.incl \
		${WRKSRC}/src/xercesc/runConfigure
	@${SED} -i '' 's| /\* argV\[\] \*/|* argV|' \
		${WRKSRC}/samples/CreateDOMDocument/CreateDOMDocument.cpp

pre-configure:
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/runConfigure
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/configure

post-configure:
.if ${PORT_OPTIONS:MEXAMPLES}
.if defined(TRANSCODER) && (${TRANSCODER} == "icu")
	@(cd ${WRKSRC}/samples && \
		${SETENV} \
		XERCESCROOT=${WRKSRC} \
		ICUROOT=${ICUROOT} \
		LDFLAGS="-L${LOCALBASE}/lib" \
		${SAMPLES_CONFIG_ENV} \
		${SH} runConfigure ${SAMPLES_CONFIG_ARGS})
.else
	@(cd ${WRKSRC}/samples && \
		${SETENV} \
		XERCESCROOT=${WRKSRC} \
		${SAMPLES_CONFIG_ENV} \
		${SH} runConfigure ${SAMPLES_CONFIG_ARGS})
.endif
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${CP} -r ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${XERCES_BINS} data
	@${CP} -r ${WRKSRC}/samples/$i ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for i in ${XERCES_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${STAGEDIR}${PREFIX}/bin
.endfor
.endif

.include <bsd.port.mk>
