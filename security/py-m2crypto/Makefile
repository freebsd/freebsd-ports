# New ports collection makefile for:	py-m2crypto
# Date created:				27 March 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	m2crypto
PORTVERSION=	0.21.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	M2Crypto-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

USE_OPENSSL=	yes
USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_BUILDARGS=	build_ext --openssl="${OPENSSLBASE}"
PYDISTUTILS_PKGNAME=	M2Crypto
PYEASYINSTALL_ARCHDEP=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/include/python$$(PYVER)|${PYTHON_INCLUDEDIR}|g' \
		-e 's|/usr/local/lib/python$$(PYVER)|${PYTHON_INCLUDEDIR}|g' \
			${WRKSRC}/SWIG/Makefile

.include <bsd.port.mk>
