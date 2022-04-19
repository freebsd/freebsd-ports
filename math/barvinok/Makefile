PORTNAME=	barvinok
DISTVERSION=	0.41.5
PORTREVISION=	1
CATEGORIES=	math
#MASTER_SITES=	http://barvinok.gforge.inria.fr/ # unavailable as of April 2022

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for counting the number of integer points in polytopes

LICENSE=	GPLv2

FETCH_DEPENDS=	git:devel/git
LIB_DEPENDS=	libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libisl.so:devel/isl \
		libntl.so:math/ntl \
		libpolylibgmp.so:math/polylib

USES=		autoreconf compiler:c11 gmake libtool localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-shared --enable-shared-barvinok \
		--with-gmp=system --with-polylib=system --with-isl=system
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

GIT_URL=	https://repo.or.cz/barvinok.git
GIT_HASH=	c58bec4907e26b9f91a734cf96c18615733ed565

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${GIT_HASH} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

.include <bsd.port.mk>
