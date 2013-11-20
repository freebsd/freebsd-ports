# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	m2crypto
PORTVERSION=	0.21.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	M2Crypto-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13

PYDISTUTILS_BUILDARGS=	build_ext --openssl="${OPENSSLBASE}"
PYDISTUTILS_PKGNAME=	M2Crypto
USE_OPENSSL=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	-2.7
MAKE_ARGS=	PYTHON_VERSION=${PYTHON_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|do_not_use_&|; /test_suite/d' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/SWIG/Makefile

.include <bsd.port.mk>
