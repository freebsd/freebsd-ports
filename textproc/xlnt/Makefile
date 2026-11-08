PORTNAME=	xlnt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ xlsx library for reading/writing/manipulating spreadsheets
WWW=		https://xlnt-community.gitbook.io/xlnt \
		https://github.com/xlnt-community/xlnt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

FETCH_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		git:devel/git
BUILD_DEPENDS=	fast_float>0:math/fast_float
LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		cmake:testing compiler:c++14-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	xlnt-community
GH_TUPLE=	nemtrif:utfcpp:6be08bb:utfcpp/third-party/utfcpp

CMAKE_OFF=	TESTS
CMAKE_TESTING_ON=	TESTS

LIBSTUDXML_NAME=	libstudxml
LIBSTUDXML_GIT_URL=	https://git.codesynthesis.com/libstudxml/libstudxml.git
LIBSTUDXML_REV=		4b801ce48b65cc12972b3a817024541614b03395

DISTFILES=	${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}${EXTRACT_SUFX}

pre-fetch: # fetch from the git repository
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${LIBSTUDXML_GIT_URL} ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} && \
	    (cd ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} && git reset -q --hard ${LIBSTUDXML_REV} && ${RM} -r .git) && \
	    ${FIND} ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV} -print0 | ${SORT} -z | \
	        ${TAR} czf ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}${EXTRACT_SUFX} --format=ustar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}; \
	fi

post-extract:
	@${RLN} ${WRKDIR}/${LIBSTUDXML_NAME}-${LIBSTUDXML_REV}/libstudxml ${WRKSRC}/third-party/libstudxml/libstudxml

# tests as of 1.6.1: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
