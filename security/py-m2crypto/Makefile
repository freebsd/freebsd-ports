# New ports collection makefile for:	py-m2crypto
# Date created:				27 March 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	m2crypto
PORTVERSION=	0.18.2
CATEGORIES=	security python
MASTER_SITES=	http://chandlerproject.org/pub/Projects/MeTooCrypto/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

USE_PYTHON=	2.3+
USE_OPENSSL=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	M2Crypto

.include <bsd.port.pre.mk>

PYDISTUTILS_BUILDARGS=	build_ext --openssl="${OPENSSLBASE}"

post-patch:
	@${REINPLACE_CMD} "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" ${WRKSRC}/SWIG/Makefile

.include <bsd.port.post.mk>
