# New ports collection makefile for: xalan-c
# Date created:		26 October 2002
# Whom:			"Bjoern A. Zeeb" (bzeeb+freebsdports@zabbadoz.net)
#
# $FreeBSD$
#
# ------------------------------------------------------------------------------

PORTNAME=	xalan-c
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	xalan-c/source xalan-c/binaries
.if defined(DEBUG)
PKGNAMESUFFIX+=		-debug
.endif
DISTNAME=	Xalan-C_${PORTVERSION:S/./_/:R:S/\..*//g}-src
.if !defined(NOPORTDOCS)
DISTFILES+=	Xalan-C_${PORTVERSION:S/./_/:R:S/\..*//g}-src${EXTRACT_SUFX} \
		${DOCS_TARBALL}
EXTRACT_ONLY=	Xalan-C_${PORTVERSION:S/./_/:R:S/\..*//g}-src${EXTRACT_SUFX}
.endif

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	XSLT processor from the Apache XML Project

.if !defined(NOPORTDOCS)
DOCS_TARBALL=	Xalan-C_${PORTVERSION:S/./_/:R:S/\..*//g}-docs${EXTRACT_SUFX}
.endif

# expect this to get broken some day
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=		yes

WRKSRC=			${WRKDIR}/xml-xalan/c
XALANWRKSRC=		${WRKSRC}/src/xalanc
CONFIGURE_WRKSRC=	${XALANWRKSRC}
BUILD_WRKSRC=		${XALANWRKSRC}
INSTALL_WRKSRC=		${XALANWRKSRC}

USE_SUBMAKE=		yes
# this IS UGLY but what should I do ? PKGNAMESUFFIX in SUBMAKE else will fail
EXTRACT_COOKIE=		${WRKDIR}/.extract_done.${PORTNAME}
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done.${PORTNAME}
INSTALL_COOKIE=		${WRKDIR}/.install_done.${PORTNAME}
BUILD_COOKIE=		${WRKDIR}/.build_done.${PORTNAME}
PATCH_COOKIE=		${WRKDIR}/.patch_done.${PORTNAME}
PACKAGE_COOKIE=		${WRKDIR}/.package_done.${PORTNAME}

USE_GMAKE=		yes
MAKE_ENV+=		XALANCROOT=${WRKSRC}
MAKE_ENV+=		XERCESCROOT=${XERCESCROOT}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ENV+=		XALANCROOT=${WRKSRC}
CONFIGURE_ENV+=		XERCESCROOT=${XERCESCROOT}
CONFIGURE_ARGS+=	-p freebsd -c ${CC} -x ${CXX} -z -I${LOCALBASE}/include -C --prefix=${PREFIX}

.include <bsd.port.pre.mk>

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.if defined(DEBUG)
CONFIGURE_ARGS+=	-d
STRIP=
.endif

# get to know this automagically depending what libxerces-c is linked against
.if defined(NO_THREADS)
CONFIGURE_ARGS+=	-r none
.else
CONFIGURE_ARGS+=	-r pthread
.endif

XALANC_LIB_VERSION=	${PORTVERSION:S/.//:R}
XALANC_LIB=		libxalan-c.so.${PORTVERSION:S/.//}
PLIST_SUB+=		XALANC_LIB=${XALANC_LIB} \
				XALANC_LIB_VERSION=${XALANC_LIB_VERSION}

SCRIPTS_ENV=		WRKDIRPREFIX="${WRKDIRPREFIX}" \
	      		WRKSRC="${WRKSRC}" \
			REALCURDIR="${.CURDIR}" \
			MKDIR="${MKDIR}" \
			PKG_INFO="${PKG_INFO}" \
			GREP="${GREP}" \
			SED="${SED}" \
			ECHO="${ECHO}" \
			TOUCH="${TOUCH}" \
			FIND="${FIND}" \
			CP="${CP}" \
			RM="${RM}" \
			CHMOD="${CHMOD}" \
			LDCONFIG="${LDCONFIG}" \
			PORTSDIR="${PORTSDIR}" \
			LOCALBASE="${LOCALBASE}" \
			XALAN_USE_ICU="${XALAN_USE_ICU}"

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
PLIST_SUB+=	NOPORTDOCS=""
.else
PLIST_SUB+=	NOPORTDOCS="@comment "
.endif

pre-everything::
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${ECHO} ''
	@${ECHO} 'You may use the following build options by defining'
	@${ECHO} 'them on the command line with -D'
	@${ECHO} ''
	@${ECHO} 'NO_THREADS	do not build a thread enabled shared library'
	@${ECHO} '		(set if xerces-c2 got compiled w/o threads)'
	@${ECHO} 'NO_SAMPLES	do not copy sample binaries and sources'
	@${ECHO} 'NOPORTDOCS	do not include documentation'
	@${ECHO} 'DEBUG		include debugging information, do not strip'
	@${ECHO} ''
	@${ECHO} 'Also you may set the following options (without -D):'
	@${ECHO} ''
	@${ECHO} 'XALAN_USE_ICU=1	if xerces-c2 got compiled with'
	@${ECHO} '		icu support and autodetect fails.'
	@${ECHO} ''
	@/bin/sleep 2
.endif
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.${PORTNAME}

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
		${_DISTDIR}/${DOCS_TARBALL} ${EXTRACT_AFTER_ARGS}
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
