# New ports collection makefile for:	cgal
# Date created:				10 Apr 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgal
PORTVERSION=	3.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mpi-sb.mpg.de/pub/outgoing/CGAL/
DISTNAME=	CGAL-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-doc_html${EXTRACT_SUFX}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A computational geometry library

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost

INSTALLS_SHLIB=	yes
SHLIB_VERSION=	0

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	install_cgal
CONFIGURE_ENV=		SHLIB_VERSION="${SHLIB_VERSION}"
CONFIGURE_ARGS=		-ni "${CXX}" --CUSTOM_CXXFLAGS "${CXXFLAGS} -I${LOCALBASE}/include"

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	lib/libCGAL.a lib/libCGAL.so lib/libCGAL.so.${SHLIB_VERSION}
PORTDOCS=	*

INVOKE=		cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

post-patch:
	@for d in ${WRKSRC}/include/CGAL ${WRKSRC}/examples ${WRKDIR}/doc_html/cgal_manual; do \
		${FIND} $$d -name '*.orig' -delete; \
	done

do-build:
.for t in lib sharedlib
	@cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} makefile_${t} ${MAKE_ARGS}
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@${INVOKE} cgal-plist SRC=include/CGAL DST=include/CGAL
	@${INVOKE} cgal-plist SRC=examples DST=%%EXAMPLESDIR%%

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libCGAL.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/src/libCGAL.so.${SHLIB_VERSION} ${PREFIX}/lib
	${LN} -sf libCGAL.so.${SHLIB_VERSION} ${PREFIX}/lib/libCGAL.so
	@${INVOKE} cgal-install SRC=${WRKSRC}/include/CGAL DST=${PREFIX}/include/CGAL
	@${INVOKE} cgal-install SRC=${WRKSRC}/examples DST=${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${INVOKE} cgal-install SRC=${WRKDIR}/doc_html/cgal_manual DST=${DOCSDIR}
.endif

cgal-plist:
	@cd ${WRKSRC}/${SRC} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|${DST}/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm ${DST}/|' >> ${PLIST}
	@${ECHO_CMD} '@dirrm ${DST}' >> ${PLIST}

cgal-install:
	cd ${SRC} && \
	${FIND} * -type d -exec ${MKDIR} "${DST}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DST}/{}" \;

.include <bsd.port.post.mk>
