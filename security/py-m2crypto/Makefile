# New ports collection makefile for:	py-m2crypto
# Date created:				27 March 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	m2crypto
PORTVERSION=	0.17
CATEGORIES=	security python
MASTER_SITES=	http://wiki.osafoundation.org/pub/Projects/MeTooCrypto/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

DIST_SUBDIR=	python
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" ${WRKSRC}/SWIG/Makefile

.include <bsd.port.mk>
