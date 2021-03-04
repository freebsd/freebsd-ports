# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	e-antic
DISTVERSION=	1.0.0-rc.13
#MASTER_SITES=	https://www.labri.fr/perso/vdelecro/e-antic/
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Real Embedded Algebraic Number Theory In C

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
LIB_DEPENDS=	libarb.so:math/arb		\
		libgmp.so:math/gmp		\
		libmpfr.so:math/mpfr		\
		libantic.so:math/antic		\
		libflint.so:math/flint2		\
		libbenchmark.so:devel/benchmark	\
		libboost_thread.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lang gmake libtool localbase	\
		python:3.7+

USE_GITHUB=	yes
ANTIC_TAG=	f4e8a60
CATCH_TAG=	ff349a5
CEREAL_TAG=	51cbda5
FLINT_TAG=	ae7ec89
UF_TAG=		0000f42
GH_ACCOUNT=	flatsurf catchorg:c1 USCiLab:c2 wbhart:f flatsurf:u
GH_PROJECT=	${PORTNAME} antic:a Catch2:c1 cereal:c2 flint2:f	\
		unique-factory:u
GH_TAGNAME=	${ANTIC_TAG}:a ${CATCH_TAG}:c1 ${CEREAL_TAG}:c2 ${FLINT_TAG}:f	\
		${UF_TAG}:u

CONFIGURE_ARGS=	--without-pytest # pytest requires cppyy

LIBS+=		"-lm"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_SUB=	VER=1.0.0rc13

post-extract:
	${CP} -R ${WRKDIR}/antic-${ANTIC_TAG}/* ${WRKSRC}/libeantic/upstream/antic/
	${CP} -R ${WRKDIR}/Catch2-${CATCH_TAG}/*	\
		${WRKSRC}/libeantic/test/external/catch2/
	${CP} -R ${WRKDIR}/cereal-${CEREAL_TAG}/*	\
		${WRKSRC}/libeantic/test/external/cereal/
	${CP} -R ${WRKDIR}/flint2-${FLINT_TAG}/* ${WRKSRC}/libeantic/upstream/antic/
	${CP} -R ${WRKDIR}/unique-factory-${UF_TAG}/*	\
		${WRKSRC}/libeantic/srcxx/external/unique-factory

post-install:
	${REINPLACE_CMD} -e 's|${STAGEDIR}||'	\
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyeantic/install_files.txt
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyeantic/install_files.txt.bak
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d \
		${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
