# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycosat
PORTVERSION=	0.6.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Bindings to PicoSAT (a SAT solver)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpicosat.so:${PORTSDIR}/devel/picosat

USES=		python
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILDARGS=	build_ext \
			-I${LOCALBASE}/include -L${LOCALBASE}/lib \
			-DDONT_INCLUDE_PICOSAT \
			-lpicosat

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/pycosat.so

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
