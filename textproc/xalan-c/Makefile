# New ports collection makefile for: xalan-c
# Date created:		26 October 2002
# Whom:			"Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
#
# $FreeBSD$
#
# ------------------------------------------------------------------------------

PORTNAME=	xalan-c
PORTVERSION=	1.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE_XML:S/$/:msax,docs/}
MASTER_SITE_SUBDIR=	${PORTNAME}/source/:msax ${PORTNAME}/docs/:docs
.if defined(DEBUG)
PKGNAMESUFFIX+=		-debug
.endif
DISTNAME=	Xalan-C_${PORTVERSION:S/./_/g}-src:msax
DISTFILES+=	Xalan-C_${PORTVERSION:S/./_/g}-src${EXTRACT_SUFX}:msax
.if !defined(NOPORTDOCS)
DISTFILES+=	${DOCS_TARBALL}:docs
EXTRACT_ONLY=	Xalan-C_${PORTVERSION:S/./_/g}-src${EXTRACT_SUFX}
.endif

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	XSLT processor from the Apache XML Project

.if !defined(NOPORTDOCS)
DOCS_TARBALL=	Xalan-C_${PORTVERSION:S/./_/g}-docs${EXTRACT_SUFX}
.endif

# we need the _extracted_ xerces-c2 port sources to build this one
# (installed version of port is enough)
XERCESC_LIB_VER?=	25
LIB_DEPENDS+=	xerces-c.${XERCESC_LIB_VER}:${PORTSDIR}/textproc/xerces-c2
XERCESCROOT?=	${LOCALBASE}

# expect this to get broken some day
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=		yes

WRKSRC=			${WRKDIR}/xml-xalan/c

USE_GMAKE=		yes
MAKE_ENV+=		XALANCROOT=${WRKSRC}
MAKE_ENV+=		XERCESCROOT=${XERCESCROOT}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ENV+=		XALANCROOT=${WRKSRC}
CONFIGURE_ENV+=		XERCESCROOT=${XERCESCROOT}
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} \
				-z -I${LOCALBASE}/include -C --prefix=${PREFIX}

.if !defined(LOCALSYS)
CONFIGURE_ARGS+=	-m inmem
PLIST_SUB+=		LOCALSYS_INMEM=""
PLIST_SUB+=		LOCALSYS_NLS="@comment "
.else
.if (${LOCALSYS} == "icu")
CONFIGURE_ARGS+=	-m icu
PLIST_SUB+=		LOCALSYS_INMEM=""
PLIST_SUB+=		LOCALSYS_NLS="@comment "
TRANSCODER=		icu
.elif (${LOCALSYS} == "nls")
CONFIGURE_ARGS+=	-m nls
PLIST_SUB+=		LOCALSYS_INMEM="@comment "
PLIST_SUB+=		LOCALSYS_NLS=""
.else
CONFIGURE_ARGS+=	-m inmem
PLIST_SUB+=		LOCALSYS_INMEM=""
PLIST_SUB+=		LOCALSYS_NLS="@comment "
.endif
.endif

.if defined(TRANSCODER) && (${TRANSCODER} == "icu")
PKGNAMESUFFIX+=		-icu
LIB_DEPENDS+=		icuuc.28:${PORTSDIR}/devel/icu2
ICUROOT?=		${LOCALBASE}
CONFIGURE_ENV+=		XALAN_USE_ICU=1
CONFIGURE_ENV+=		ICUROOT=${ICUROOT}
CONFIGURE_ARGS+=	-t icu
MAKE_ENV+=		XALAN_USE_ICU=1
MAKE_ENV+=		ICUROOT=${ICUROOT}
PLIST_SUB+=		ICUDEP=""
.else
LIB_DEPENDS+=		iconv:${PORTSDIR}/converters/libiconv
CONFIGURE_ENV+=		LDFLAGS='-L${LOCALBASE}/lib -liconv'
MAKE_ENV+=		LDFLAGS='-L${LOCALBASE}/lib -liconv'
PLIST_SUB+=		ICUDEP="@comment "
.endif

.if defined(DEBUG)
CONFIGURE_ARGS+=	-d
STRIP=
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=			"Does not compile on FreeBSD >= 5.x"
.else
BROKEN=			"Broken dependency"
.endif

.if defined(ARCH) && \
	(${ARCH} == "alpha" || ${ARCH} == "sparc64" || \
	${ARCH} == "amd64" || ${ARCH} == "ia64")
# set bitsToBuild to 64
CONFIGURE_ARGS+=	-b 64
SAMPLES_CONFIG_ARGS+=	-b 64
.endif

XALANC_LIB_VERSION=	${PORTVERSION:S/.//:R}
XALANC_LIB=		libxalan-c.so.${PORTVERSION:S/.//}
XALANMSG_LIB=		libxalanMsg.so.${PORTVERSION:S/.//}
PLIST_SUB+=		XALANC_LIB=${XALANC_LIB} \
				XALANMSG_LIB=${XALANMSG_LIB} \
				XALANC_LIB_VERSION=${XALANC_LIB_VERSION}

.if !defined(NO_SAMPLES)
PLIST_SUB+=	NO_SAMPLES=""
ALL_TARGET?=	all samples
SAMPLE_BINS=	CompileStylesheet DocumentBuilder ExternalFunction \
		ParsedSourceWrappers SerializeNodeSet SimpleTransform \
		SimpleXPathAPI SimpleXPathCAPI StreamTransform \
		TraceListen TransformToXercesDOM UseStylesheetParam \
		XPathWrapper XalanTransform XalanTransformerCallback
.else
PLIST_SUB+=	NO_SAMPLES="@comment "
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-everything::
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${ECHO} ''
	@${ECHO} 'You may use the following build options by defining'
	@${ECHO} 'them on the command line with -D'
	@${ECHO} ''
	@${ECHO} 'NO_SAMPLES	do not copy sample binaries and sources'
	@${ECHO} 'NOPORTDOCS	do not include documentation'
	@${ECHO} 'DEBUG		include debugging information, do not strip'
	@${ECHO} ''
	@${ECHO} 'Also you may set the following options (without -D):'
	@${ECHO} ''
	@${ECHO} 'LOCALSYS=[inmem|nls|icu]	default:inmem'
	@${ECHO} 'TRANSCODER=icu	(most likely if xerces-c2 also' \
					'compiled with icu support)'
	@${ECHO} ''
	@/bin/sleep 2
.endif

post-install:
.if !defined(DEBUG)
	@${STRIP_CMD} ${PREFIX}/lib/${XALANC_LIB}
.endif
.if !defined(NO_SAMPLES)
.for i in ${SAMPLE_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
.if exists(${.CURDIR}/Makefile.inc-sample-src)
.include "${.CURDIR}/Makefile.inc-sample-src"
.endif
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${DOCSDIR} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${DOCS_TARBALL} ${EXTRACT_AFTER_ARGS} && \
	${MV} ${DOCSDIR}/Xalan-C_${PORTVERSION:S/./_/g}-docs/* ${DOCSDIR} && \
	${RMDIR} ${DOCSDIR}/Xalan-C_${PORTVERSION:S/./_/g}-docs
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
