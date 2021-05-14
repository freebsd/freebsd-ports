PORTNAME=	xlnt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0-92
DISTVERSIONSUFFIX=	-g20f3dac2
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ xlsx library for reading/writing/manipulating spreadsheets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

FETCH_DEPENDS=	git:devel/git

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	tfussell

CMAKE_OFF=	TESTS

LIBSTUDXML_NAME=	libstudxml
LIBSTUDXML_GIT_URL=	https://git.codesynthesis.com/libstudxml/libstudxml.git
LIBSTUDXML_REV=		e729667

DISTFILES=	${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}${EXTRACT_SUFX}

pre-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${LIBSTUDXML_GIT_URL} ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} && \
	    (cd ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} && git reset -q --hard ${LIBSTUDXML_REV} && ${RM} -r .git) && \
	    ${FIND} ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}; \
	fi

post-extract:
	@${RLN} ${WRKDIR}/${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}/libstudxml ${WRKSRC}/third-party/libstudxml/libstudxml

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
