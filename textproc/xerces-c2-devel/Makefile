# New ports collection makefile for:	xerces-c2
# Date created:		06 September 2002
# Whom:			"Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
#
# $FreeBSD$
#

PORTNAME=	xerces-c2
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	xerces-c/source
DISTNAME=	xerces-c-src_${PORTVERSION:S/./_/g}

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	Validating XML parser from the Apache XML Project

.if !defined(TRANSCODER)
LIB_DEPENDS+=		iconv.3:${PORTSDIR}/converters/libiconv
TRANSCODER=		"IconvFBSD"
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.else
.if (${TRANSCODER} == "icu")
PKGNAMESUFFIX+=		-icu2
LIB_DEPENDS+=		icuuc.26:${PORTSDIR}/devel/icu2
ICUROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		ICUROOT=${ICUROOT} LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV+=		ICUROOT=${ICUROOT} LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB+=		TRANSICONV="@comment "
PLIST_SUB+=		TRANSICU=""
.elif (${TRANSCODER} == "native")
PKGNAMESUFFIX+=		-native
PLIST_SUB+=		TRANSICONV=""
PLIST_SUB+=		TRANSICU="@comment "
.else
LIB_DEPENDS+=		iconv.3:${PORTSDIR}/converters/libiconv
TRANSCODER=		"IconvFBSD"
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

USE_GMAKE=		yes
MAKE_ENV+=		XERCESCROOT=${WRKSRC}

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		XERCESCROOT=${WRKSRC} TRANSCODER=${TRANSCODER}
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} -n socket -P ${PREFIX}

CONFIGURE_ARGS+=	-t ${TRANSCODER}

.include <bsd.port.pre.mk>

.if defined(DEBUG)
PKGNAMESUFFIX+=		-debug
CONFIGURE_ARGS+=	-d
STRIP=
.endif

.if defined(NO_THREADS)
CONFIGURE_ARGS+=	-r none
.endif

XERCESC_LIB_VERSION=	${PORTVERSION:S/.//:R}
XERCESC_LIB=		libxerces-c.so.${PORTVERSION:S/.//}
PLIST_SUB+=		XERCESC_LIB=${XERCESC_LIB} \
				XERCESC_LIB_VERSION=${XERCESC_LIB_VERSION}

.if !defined(NO_SAMPLES)
PLIST_SUB+=	NO_SAMPLES=""
ALL_TARGET?=	all samples
XERCES_BINS?=	CreateDOMDocument DOMCount DOMPrint EnumVal MemParse PParse \
	Redirect SAX2Count SAX2Print SAXCount SAXPrint SEnumVal StdInParse
SAMPLES_CONFIG_ARGS+=	-p freebsd -c ${CC} -x ${CXX}
.if defined(NO_THREADS)
SAMPLES_CONFIG_ARGS+=	-r none
.else
SAMPLES_CONFIG_ARGS+=	-r pthread
.endif
.else
PLIST_SUB+=	NO_SAMPLES="@comment "
.endif

pre-everything::
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@(/usr/bin/dialog --textbox ${MASTERDIR}/pkg-message 15 75 || \
		${TRUE})
	@${ECHO} ''
	@${ECHO} 'You may use the following build options by defining'
	@${ECHO} 'them on the command line with -D'
	@${ECHO} ''
	@${ECHO} 'NO_THREADS	do not build a thread enabled shared library'
	@${ECHO} 'NO_SAMPLES	do not copy sample binaries and sources'
	@${ECHO} 'NOPORTDOCS	do not copy documentation'
	@${ECHO} 'DEBUG		include debugging information, do not strip'
	@${ECHO} ''
	@${ECHO} 'Also you may set TRANSCODER to the following values (without -D):'
	@${ECHO} ''
	@${ECHO} 'TRANSCODER=[icu|IconvFBSD|native]	default: IconvFBSD'
	@${ECHO} ''
	@/bin/sleep 2
.endif

post-patch:
	@${CP} ${WRKSRC}/src/xercesc/Makefile.incl \
		${WRKSRC}/src/xercesc/Makefile.incl.Dist
	@${SED} -e 's#CP = -cp -p#CP = -cp#' \
		${WRKSRC}/src/xercesc/Makefile.incl.Dist > \
		${WRKSRC}/src/xercesc/Makefile.incl

pre-configure:
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/runConfigure
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/configure

post-configure:
.if !defined(NO_SAMPLES)
.if defined(TRANSCODER) && (${TRANSCODER} == "icu")
	@(cd ${WRKSRC}/samples && \
		export XERCESCROOT=${WRKSRC} && \
		export ICUROOT=${ICUROOT} && \
		export LDFLAGS="-L${LOCALBASE}/lib" && \
		${SH} runConfigure ${SAMPLES_CONFIG_ARGS})
.else
	@(cd ${WRKSRC}/samples && \
		export XERCESCROOT=${WRKSRC} && \
		${SH} runConfigure ${SAMPLES_CONFIG_ARGS})
.endif
.endif

post-install:
.if !defined(DEBUG)
	@${STRIP_CMD} ${PREFIX}/lib/${XERCESC_LIB}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xerces-c
	@${CP} -r ${WRKSRC}/doc/ ${PREFIX}/share/doc/xerces-c/
.endif
.if !defined(NO_SAMPLES)
	@${MKDIR} ${PREFIX}/share/xerces-c
.for i in ${XERCES_BINS} data
	@${CP} -r ${WRKSRC}/samples/$i ${PREFIX}/share/xerces-c/
.endfor
.for i in ${XERCES_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
.endif

.include <bsd.port.post.mk>
