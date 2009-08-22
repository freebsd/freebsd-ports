# ex:ts=8
# Ports collection makefile for:	py-openssl
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSL-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to the OpenSSL library

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyOpenSSL
USE_OPENSSL=	yes

pre-configure:
	@${ECHO_CMD} "[build_ext]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "include-dirs = ${OPENSSLINC}" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "library-dirs = ${OPENSSLLIB}" >> ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
