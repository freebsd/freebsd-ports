PORTNAME=	ttmath
DISTVERSION=	0.9.3.20191013
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ headers-only library for big integer and floating point numbers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

FETCH_DEPENDS=	git:devel/git

USES=		cmake:testing

NO_BUILD=	yes
NO_ARCH=	yes

GIT_URL=	https://gitea.ttmath.org/tomasz.sowa/ttmath.git
GIT_TAG=	aad580f51e7ffc32966507a9897ec575c389e3e6

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${GIT_TAG} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
