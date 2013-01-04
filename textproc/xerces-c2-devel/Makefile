# Created by: "Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
# $FreeBSD$

PORTNAME=	xerces-c2-devel
PORTVERSION=	2.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	xerces/c/sources
DISTNAME=	xerces-c-src_${PORTVERSION:S/./_/g}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Validating XML parser from the Apache XML Project

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		THREADS DEBUG ICONVFBSD ICU NATIVE
OPTIONS_DEFAULT=	THREADS ICONVFBSD

THREADS_DESC=		Build a thread enabled shared library
DEBUG_DESC=		Include debugging information, do not strip
ICONVFBSD_DESC=		Use IconvFBSD transcoder
ICU_DESC=		Use ICU transcoder
NATIVE_DESC=		Use native transcoder

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNATIVE}
TRANSCODER=		native
.endif

.if ${PORT_OPTIONS:MICU}
TRANSCODER=		icu
.endif

.if ${PORT_OPTIONS:MICONVFBSD}
TRANSCODER=		IconvFBSD
.endif

.if !defined(TRANSCODER)
USE_ICONV=		yes
TRANSCODER=		IconvFBSD
ICONVROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		ICONVROOT=${ICONVROOT}
MAKE_ENV+=		ICONVROOT=${ICONVROOT}
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.else
.if (${TRANSCODER} == "icu")
PKGNAMESUFFIX+=		-icu
LIB_DEPENDS+=		icuuc:${PORTSDIR}/devel/icu
ICUROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		ICUROOT=${ICUROOT}
MAKE_ENV+=		ICUROOT=${ICUROOT}
PLIST_SUB+=		TRANSICONV="@comment "
PLIST_SUB+=		TRANSICU=""
.elif (${TRANSCODER} == "native")
PKGNAMESUFFIX+=		-native
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.else
USE_ICONV=		yes
TRANSCODER=		IconvFBSD
ICONVROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		ICONVROOT=${ICONVROOT}
MAKE_ENV+=		ICONVROOT=${ICONVROOT}
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.endif
.endif

USE_LDCONFIG=	yes

XERCESWRKSRC=		${WRKSRC}/src/xercesc
CONFIGURE_WRKSRC=	${XERCESWRKSRC}
BUILD_WRKSRC=		${XERCESWRKSRC}
INSTALL_WRKSRC=		${XERCESWRKSRC}

USE_GMAKE=		yes
MAKE_ENV+=		XERCESCROOT=${WRKSRC}

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

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=	-r none
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
.if ${PORT_OPTIONS:MTHREADS}
SAMPLES_CONFIG_ARGS+=	-r pthread
SAMPLES_CONFIG_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.else
SAMPLES_CONFIG_ARGS+=	-r none
.endif
.endif

PORTDOCS=	*

SCRIPTS_ENV=	WITH_NATIVE="${WITH_NATIVE}" \
		WITH_ICU="${WITH_ICU}" \
		WITH_ICONVFBSD="${WITH_ICONVFBSD}"

pre-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/check-config-options

post-patch:
	@${REINPLACE_CMD} -e 's#CP = -cp -p#CP = -cp#'	\
		${WRKSRC}/src/xercesc/Makefile.incl
.if ${OSVERSION} < 700000
	@${REINPLACE_CMD} -e 's,-lgcc,-lgcc_pic,' \
		${WRKSRC}/src/xercesc/Makefile.incl
.endif
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
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/doc/ ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for i in ${XERCES_BINS} data
	@${CP} -r ${WRKSRC}/samples/$i ${EXAMPLESDIR}
.endfor
.for i in ${XERCES_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
.endif

.include <bsd.port.mk>
