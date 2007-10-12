# New ports collection makefile for:	py-vertex
# Date created:				19 May 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	vertex
PORTVERSION=	0.2.0
CATEGORIES=	net-p2p python
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Vertex-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vertex is an implementation of the Q2Q protocol

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/epsilon/__init__.py:${PORTSDIR}/devel/py-epsilon \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/epsilon/__init__.py:${PORTSDIR}/devel/py-epsilon \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Vertex
USE_TWISTED=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
