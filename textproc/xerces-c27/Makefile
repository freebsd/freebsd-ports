# New ports collection makefile for:	xerces-c2
# Date created:		06 September 2002
# Whom:			"Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
#
# $FreeBSD$
#

PORTNAME=	xerces-c2
PORTVERSION=	2.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-c/stable/
DISTNAME=	xerces-c-src${PORTVERSION:S/./_/g}

MAINTAINER?=	bzeeb+freebsdports@zabbadoz.net

LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv

# expect this to get broken some day
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		${PREFIX}/lib
NOCLEANDEPENDS=		yes

XERCESWRKSRC=		${WRKSRC}/src/xercesc
CONFIGURE_WRKSRC=	${XERCESWRKSRC}
BUILD_WRKSRC=		${XERCESWRKSRC}
INSTALL_WRKSRC=		${XERCESWRKSRC}

USE_GMAKE=		yes
MAKE_ENV+=		XERCESCROOT=${WRKSRC}

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		XERCESCROOT=${WRKSRC} TRANSCODER="IconvFBSD"
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ARGS?=	-p freebsd -x g++ -n socket -P ${PREFIX}

CONFIGURE_ARGS+=	-t IconvFBSD

.if defined(NO_THREADS)
CONFIGURE_ARGS+=	-r none
.endif

XERCESC_LIB=		libxerces-c.so.${PORTVERSION:S/.//}
PLIST_SUB+=		XERCESC_LIB=${XERCESC_LIB}

.if !defined(NO_SAMPLES)
PLIST_SUB+=	NO_SAMPLES=""
ALL_TARGET?=	all samples
XERCES_BINS?=	CreateDOMDocument DOMCount DOMPrint EnumVal MemParse PParse \
	Redirect SAX2Count SAX2Print SAXCount SAXPrint SEnumVal StdInParse
SAMPLES_CONFIG_ARGS?=	-p freebsd -x g++
.if defined(NO_THREADS)
SAMPLES_CONFIG_ARGS+=	-r none
.endif
.else
PLIST_SUB+=	NO_SAMPLES="@comment "
.endif

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@(/usr/bin/dialog --textbox ${MASTERDIR}/pkg-message 15 75 || \
		/usr/bin/true)
	@${ECHO} ''
	@${ECHO} 'You may use the following build options by defining'
	@${ECHO} 'them on the command line with -D'
	@${ECHO} ''
	@${ECHO} 'NO_THREADS	do not build a thread enabled shared library'
	@${ECHO} 'NO_SAMPLES	do not copy sample binaries and sources'
	@${ECHO} 'NOPORTDOCS	do not copy documentation'
	@${ECHO} ''
	@/bin/sleep 2
.endif

pre-configure:
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/runConfigure
	@${CHMOD} 700 ${CONFIGURE_WRKSRC}/configure

post-configure:
.if !defined(NO_SAMPLES)
	@(cd ${WRKSRC}/samples && \
		export XERCESCROOT=${WRKSRC} && \
		${SH} runConfigure ${SAMPLES_CONFIG_ARGS})
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/${XERCESC_LIB}
	${LN} -sf ${XERCESC_LIB} ${PREFIX}/lib/libxerces-c.so
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

.include <bsd.port.mk>
