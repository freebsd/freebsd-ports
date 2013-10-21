# Created by: Bjoern A. Zeeb <bz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xalan-c
PORTVERSION=	1.11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:msax,docs/}
MASTER_SITE_SUBDIR=	xalan/${PORTNAME}/sources/:msax xalan/${PORTNAME}/docs/:docs
DISTNAME=	xalan_c-${PORTVERSION}-src:msax
DISTFILES+=	xalan_c-${PORTVERSION}-src${EXTRACT_SUFX}:msax

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSLT processor from the Apache XML Project

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

# move this further down though portlint might not like it but without
# this I will not be able to make use of make config in the future.
.if ${PORT_OPTIONS:MDEBUG}
PKGNAMESUFFIX+=		-debug
.endif
.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DOCS_TARBALL}:docs
EXTRACT_ONLY=	xalan_c-${PORTVERSION}-src${EXTRACT_SUFX}
DOCS_TARBALL=	xalan_c-${PORTVERSION}-docs-html-nograf${EXTRACT_SUFX}
.endif

# we need the _extracted_ xerces-c3 port sources to build this one
# (installed version of port is enough)
XERCESC_LIB_VER?=	3
LIB_DEPENDS+=	xerces-c.${XERCESC_LIB_VER}:${PORTSDIR}/textproc/xerces-c3
XERCESCROOT?=	${LOCALBASE}

USE_LDCONFIG=	yes

WRKSRC=			${WRKDIR}/xalan-c-${PORTVERSION}/c

USE_GMAKE=		yes
MAKE_ENV+=		XALANCROOT=${WRKSRC}
MAKE_ENV+=		XERCESCROOT=${XERCESCROOT}
MAKE_JOBS_UNSAFE=

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ENV+=		XALANCROOT=${WRKSRC}
CONFIGURE_ENV+=		XERCESCROOT=${XERCESCROOT}
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} -l ${PTHREAD_LIBS} \
				-z ${EXTRA_CFLAGS} -I${LOCALBASE}/include -C --prefix=${PREFIX}

CONFIGURE_ARGS+=	-m inmem

.if ${PORT_OPTIONS:MDEBUG}
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
XALANC_LIB=		libxalan-c.so.${PORTVERSION:S/.//}.0
XALANMSG_LIB=		libxalanMsg.so.${PORTVERSION:S/.//}.0
PLIST_SUB+=		XALANC_LIB=${XALANC_LIB} \
				XALANMSG_LIB=${XALANMSG_LIB} \
				XALANC_LIB_VERSION=${XALANC_LIB_VERSION}

.if ${PORT_OPTIONS:MEXAMPLES}
ALL_TARGET?=	all samples
SAMPLE_BINS=	CompileStylesheet DocumentBuilder ExternalFunction \
		ParsedSourceWrappers SerializeNodeSet SimpleTransform \
		SimpleXPathAPI SimpleXPathCAPI StreamTransform \
		TraceListen TransformToXercesDOM UseStylesheetParam \
		XalanTransform XalanTransformerCallback ThreadSafe
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

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
.if !${PORT_OPTIONS:MDEBUG}
	@${STRIP_CMD} ${PREFIX}/lib/${XALANC_LIB}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
.for i in ${SAMPLE_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
.if exists(${.CURDIR}/Makefile.inc-sample-src)
.include "${.CURDIR}/Makefile.inc-sample-src"
.endif
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${DOCSDIR} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${DOCS_TARBALL} ${EXTRACT_AFTER_ARGS} && \
	${MV} ${DOCSDIR}/docs/xalan-c/* ${DOCSDIR} && \
	${RMDIR} ${DOCSDIR}/docs/xalan-c && \
	${RMDIR} ${DOCSDIR}/docs
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
