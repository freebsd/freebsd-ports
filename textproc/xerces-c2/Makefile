# New ports collection makefile for:	xerces-c2
# Date created:		06 September 2002
# Whom:			"Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
#
# $FreeBSD$
#

PORTNAME=	xerces-c2
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	xerces-c/source
DISTNAME=	xerces-c-src_${PORTVERSION:S/./_/g}

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	Validating XML parser from the Apache XML Project

OPTIONS=	THREADS "Build a thread enabled shared library." on \
		SAMPLES "Copy sample binaries and sources." on \
		PORTDOCS "Copy documentation." on \
		DEBUG "Include debugging information, do not strip." off \
		ICONVFBSD "Use IconvFBSD transcoder." on \
		ICU "Use ICU transcoder." off \
		NATIVE "Use native transcoder." off

.include <bsd.port.pre.mk>

.if defined(WITH_NATIVE)
TRANSCODER=		native
.endif
.if defined(WITH_ICU)
TRANSCODER=		icu
.endif
.if defined(WITH_ICONVFBSD)
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
LIB_DEPENDS+=		icuuc.32:${PORTSDIR}/devel/icu
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

# expect this to get broken some day
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=		yes

XERCESWRKSRC=		${WRKSRC}/src/xercesc
CONFIGURE_WRKSRC=	${XERCESWRKSRC}
BUILD_WRKSRC=		${XERCESWRKSRC}
INSTALL_WRKSRC=		${XERCESWRKSRC}

USE_REINPLACE=		yes
USE_GMAKE=		yes
MAKE_ENV+=		XERCESCROOT=${WRKSRC}

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		XERCESCROOT=${WRKSRC} TRANSCODER=${TRANSCODER}
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} -n socket -P ${PREFIX}

CONFIGURE_ARGS+=	-t ${TRANSCODER}

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	-d
STRIP=
.endif

.if defined(ARCH) && \
	(${ARCH} == "alpha" || ${ARCH} == "sparc64" || \
	${ARCH} == "amd64" || ${ARCH} == "ia64")
# set bitsToBuild to 64
CONFIGURE_ARGS+=	-b 64
SAMPLES_CONFIG_ARGS+=	-b 64
.endif

.if defined(WITHOUT_THREADS)
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

.if !defined(WITHOUT_SAMPLES)
PLIST_SUB+=	NO_SAMPLES=""
ALL_TARGET?=	all samples
XERCES_BINS?=	CreateDOMDocument DOMCount DOMPrint EnumVal MemParse PParse \
		PSVIWriter Redirect SAX2Count SAX2Print SAXCount SAXPrint \
		SCMPrint SEnumVal StdInParse
SAMPLES_CONFIG_ARGS+=	-p freebsd -c ${CC} -x ${CXX}
.if defined(WITHOUT_THREADS)
SAMPLES_CONFIG_ARGS+=	-r none
.else
SAMPLES_CONFIG_ARGS+=	-r pthread
SAMPLES_CONFIG_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif
.else
PLIST_SUB+=	NO_SAMPLES="@comment "
.endif

.if !defined(WITHOUT_PORTDOCS)
PORTDOCS=	*
.endif

SCRIPTS_ENV=	WITH_NATIVE="${WITH_NATIVE}" \
		WITH_ICU="${WITH_ICU}" \
		WITH_ICONVFBSD="${WITH_ICONVFBSD}"

pre-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/check-config-options

post-patch:
	@${REINPLACE_CMD} -e 's#CP = -cp -p#CP = -cp#'	\
		${WRKSRC}/src/xercesc/Makefile.incl

pre-configure:
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/runConfigure
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/configure

post-configure:
.if !defined(WITHOUT_SAMPLES)
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
.if defined(WITHOUT_DEBUG)
	@${STRIP_CMD} ${PREFIX}/lib/${XERCESC_LIB}
	@${STRIP_CMD} ${PREFIX}/lib/${XERCESC_DEPDOM_LIB}
.endif
.if !defined(WITHOUT_PORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/doc/ ${DOCSDIR}
.endif
.if !defined(WITHOUT_SAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for i in ${XERCES_BINS} data
	@${CP} -r ${WRKSRC}/samples/$i ${EXAMPLESDIR}
.endfor
.for i in ${XERCES_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
.endif

.include <bsd.port.post.mk>
