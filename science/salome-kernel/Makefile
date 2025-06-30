PORTNAME=	salome-kernel
DISTVERSIONPREFIX=	V
DISTVERSION=	9_11_0
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Salome Project: Multi-physics simulations: Kernel
WWW=		https://www.salome-platform.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expired science/salome-configuration
EXPIRATION_DATE=2025-09-30

FETCH_DEPENDS=	git:devel/git
PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}omniorb>0:devel/py-omniorb \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	salome-configuration>0:science/salome-configuration \
		swig:devel/swig \
		${PY_DEPENDS}
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libomniORB4.so:devel/omniORB
RUN_DEPENDS=	bash:shells/bash \
		${PY_DEPENDS}

USES=		cmake compiler:c++11-lang gnome python shebangfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py *.sh
SHEBANG_FILES=	bin/appliskel/salome \
		bin/appliskel/salome_mesa \
		bin/appliskel/.salome_run \
		bin/appliskel/.bashrc

GIT_URL=	https://git.salome-platform.org/gitpub/modules/kernel # all Salome repositories: https://git.salome-platform.org/gitweb/

CMAKE_ARGS=	-DCONFIGURATION_ROOT_DIR=${LOCALBASE}/share/salome/configuration \
		-DOMNIORBPY_ROOT_DIR=${LOCALBASE} \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	SALOME_BUILD_TESTS SALOME_BUILD_DOC
CFLAGS+=	-DSIZEOF_INT=4 -DSIZEOF_LONG=4
LDFLAGS+=	-lexecinfo

DATADIR=	${PREFIX}/share/salome

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${DISTVERSIONFULL} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=ustar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

.include <bsd.port.mk>
