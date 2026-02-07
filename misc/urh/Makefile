PORTNAME=	urh
DISTVERSION=	2.9.8
PORTREVISION=	2
CATEGORIES=	misc hamradio python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Radio Hacker: investigate wireless protocols like a boss
WWW=		https://github.com/jopohl/urh/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}

USES=		fortran localbase python pyqt:6
USE_PYQT=	pyqt6
USE_PYTHON=	autoplist cython distutils noflavors

PLIST_FILES=	bin/urh.shadow

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/urh ${STAGEDIR}${PREFIX}/bin/urh.shadow
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so ${PREFIX}/bin/urh.shadow \"$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/urh
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/urh
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/urh/cythonext/*.so

.include <bsd.port.mk>
