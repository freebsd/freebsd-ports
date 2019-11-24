# $FreeBSD$

PORTNAME=	urh
DISTVERSION=	2.8.1
CATEGORIES=	misc hamradio python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Radio Hacker: investigate wireless protocols like a boss

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libomp.so:devel/openmp
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}

USES=		compiler:c++11-lang fortran python:3.4+ localbase pyqt:5
USE_PYQT=	core gui test widgets
USE_PYTHON=	distutils cython noflavors autoplist

PLIST_FILES=	bin/urh.shadow

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/urh ${STAGEDIR}${PREFIX}/bin/urh.shadow
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so ${PREFIX}/bin/urh.shadow \"$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/urh
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/urh

.include <bsd.port.mk>
