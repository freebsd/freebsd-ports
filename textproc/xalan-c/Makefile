# New ports collection makefile for: xalan-c
# Date created:		26 October 2002
# Whom:			"Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
#
# $FreeBSD$
#
# ------------------------------------------------------------------------------

PORTNAME=	xalan-c
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE_XML:S/$/:msax,docs/}
MASTER_SITE_SUBDIR=	${PORTNAME}/source/:msax ${PORTNAME}/docs/:docs
DISTNAME=	Xalan-C_${PORTVERSION:S/./_/g}-src:msax
DISTFILES+=	Xalan-C_${PORTVERSION:S/./_/g}-src${EXTRACT_SUFX}:msax

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSLT processor from the Apache XML Project

OPTIONS=	INMEM "Use inmem locale system." on \
		ICU "Use ICU locale system." off \
		NLS "Use nls locale system." off \
		TRANSCODER_ICU "Use ICU transcoder (if used in xerces-c2)." off \
		SAMPLES "Copy sample binaries and sources." on \
		PORTDOCS "Copy documentation." on \
		DEBUG "Include debugging information, do not strip." off

.include <bsd.port.pre.mk>

# move this further down though portlint might not like it but without
# this I will not be able to make use of make config in the future.
.if defined(WITH_DEBUG)
PKGNAMESUFFIX+=		-debug
.endif
.if defined(WITHOUT_PORTDOCS)
NOPORTDOCS=	yes
.endif
.if !defined(NOPORTDOCS)
DISTFILES+=	${DOCS_TARBALL}:docs
EXTRACT_ONLY=	Xalan-C_${PORTVERSION:S/./_/g}-src${EXTRACT_SUFX}
DOCS_TARBALL=	Xalan-C_${PORTVERSION:S/./_/g}-docs${EXTRACT_SUFX}
.endif

# we need the _extracted_ xerces-c2 port sources to build this one
# (installed version of port is enough)
XERCESC_LIB_VER?=	27
LIB_DEPENDS+=	xerces-c.${XERCESC_LIB_VER}:${PORTSDIR}/textproc/xerces-c2
XERCESCROOT?=	${LOCALBASE}

# expect this to get broken some day
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=		yes

WRKSRC=			${WRKDIR}/xml-xalan/c

USE_GMAKE=		yes
MAKE_ENV+=		XALANCROOT=${WRKSRC}
MAKE_ENV+=		XERCESCROOT=${XERCESCROOT}

.if ( ${OSVERSION} < 500000 )
EXTRA_CFLAGS=		-ftemplate-depth-20
.endif

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ENV+=		XALANCROOT=${WRKSRC}
CONFIGURE_ENV+=		XERCESCROOT=${XERCESCROOT}
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} -l ${PTHREAD_LIBS} \
				-z ${EXTRA_CFLAGS} -I${LOCALBASE}/include -C --prefix=${PREFIX}

.if defined(WITH_INMEM)
LOCALSYS=		inmem
.endif
.if defined(WITH_ICU)
LOCALSYS=		icu
.endif
.if defined(WITH_NLS)
LOCALSYS=		nls
.endif

.if !defined(LOCALSYS)
CONFIGURE_ARGS+=	-m inmem
PLIST_SUB+=		LOCALSYS_INMEM=""
PLIST_SUB+=		LOCALSYS_NLS="@comment "
.else
.if (${LOCALSYS} == "icu")
CONFIGURE_ARGS+=	-m icu
PLIST_SUB+=		LOCALSYS_INMEM=""
PLIST_SUB+=		LOCALSYS_NLS="@comment "
WITH_TRANSCODER_ICU=	icu
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

.if defined(WITH_TRANSCODER_ICU)
PKGNAMESUFFIX+=		-icu
LIB_DEPENDS+=		icuuc.32:${PORTSDIR}/devel/icu
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

.if defined(WITH_DEBUG)
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

XALANC_LIB_VERSION=	${PORTVERSION:S/.//:R}
XALANC_LIB=		libxalan-c.so.${PORTVERSION:S/.//}
XALANMSG_LIB=		libxalanMsg.so.${PORTVERSION:S/.//}
PLIST_SUB+=		XALANC_LIB=${XALANC_LIB} \
				XALANMSG_LIB=${XALANMSG_LIB} \
				XALANC_LIB_VERSION=${XALANC_LIB_VERSION}

.if !defined(WITHOUT_SAMPLES)
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

SCRIPTS_ENV=	WITH_INMEM="${WITH_INMEM}" \
		WITH_ICU="${WITH_ICU}" \
		WITH_NLS="${WITH_NLS}"

pre-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/check-config-options

post-patch:
	${RM} -f ${WRKSRC}/src/xalanc/ICUBridge/ICUFormatNumberFunctor.hpp.orig \
		${WRKSRC}/src/xalanc/PlatformSupport/XalanArrayAllocator.hpp.orig \
		${WRKSRC}/src/xalanc/XMLSupport/FormatterToText.hpp.orig \
		${WRKSRC}/src/xalanc/XPath/ElementPrefixResolverProxy.hpp.orig \
		${WRKSRC}/src/xalanc/XPath/NameSpace.hpp.orig \
		${WRKSRC}/src/xalanc/XPath/XalanQNameByValue.hpp.orig \
		${WRKSRC}/src/xalanc/XSLT/FunctionSystemProperty.hpp.orig \
		${WRKSRC}/src/xalanc/XSLT/TopLevelArg.hpp.orig
	${CHMOD} 755 ${WRKSRC}/runConfigure ${WRKSRC}/configure

post-install:
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/lib/${XALANC_LIB}
.endif
.if !defined(WITHOUT_SAMPLES)
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
