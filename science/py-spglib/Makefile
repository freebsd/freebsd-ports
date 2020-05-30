# $FreeBSD$

PORTNAME=	spglib
DISTVERSION=	1.15.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding and handling crystal symmetries (python binding)

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spglib/_spglib.so

.include <bsd.port.mk>
