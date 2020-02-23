# $FreeBSD$

PORTNAME=	symcxx
DISTVERSION=	0.1.9
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal symbolic manipulation python package written in C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang fortran python:-3.6 # fortran because otherwise "import numpy" fails with wrong libgcc_s.so message
USE_PYTHON=	distutils autoplist

post-patch:
	@truncate -s 0 ${WRKSRC}/README.rst # workaround for https://github.com/bjodah/symcxx/issues/19

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/symcxx/_symcxx.so

.include <bsd.port.mk>
