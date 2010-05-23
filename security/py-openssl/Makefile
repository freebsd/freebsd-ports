# ex:ts=8
# Ports collection makefile for:	py-openssl
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.10
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSL-${PORTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Python interface to the OpenSSL library

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyOpenSSL
USE_OPENSSL=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

pre-configure:
	@${ECHO_CMD} "[build_ext]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "include-dirs = ${OPENSSLINC}" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "library-dirs = ${OPENSSLLIB}" >> ${WRKSRC}/setup.cfg

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
