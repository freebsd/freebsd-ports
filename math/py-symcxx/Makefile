# $FreeBSD$

PORTNAME=	symcxx
DISTVERSION=	0.1.10
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal symbolic manipulation python package written in C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang fortran python # fortran because otherwise "import numpy" fails with wrong libgcc_s.so message
USE_PYTHON=	distutils autoplist

post-patch:
	@truncate -s 0 ${WRKSRC}/README.rst # workaround for https://github.com/bjodah/symcxx/issues/19

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/symcxx/_symcxx.so

.include <bsd.port.mk>
