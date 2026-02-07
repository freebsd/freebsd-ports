# levmar library (math/levmar) is bundled

PORTNAME=	levmar
DISTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Binding to levmar library (Levenberg-Marquardt optimization algorithm)
WWW=		https://github.com/bjodah/levmar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		doesn't build with Python-3.11, 4 authors were notified via e-mail on 2024-06-02

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
TEST_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ö|o|' ${WRKSRC}/AUTHORS # breaks because of non-ascii chars

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_${PORTNAME}*.so

do-test:
	@cd ${WRKSRC}/levmar/tests && ${PYTHON_CMD} -m pytest --pyargs levmar

.include <bsd.port.post.mk>
