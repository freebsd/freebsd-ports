PORTNAME=	pyodeint
DISTVERSION=	0.10.4
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for odeint from boost
WWW=		https://github.com/bjodah/pyodeint

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/include/boost/config.hpp:devel/boost-libs
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang localbase python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
