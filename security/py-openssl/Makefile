# Created by: ijliao
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	0.13
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSL-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python interface to the OpenSSL library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyOpenSSL
USE_OPENSSL=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

NO_STAGE=	yes
pre-configure:
	@${ECHO_CMD} "[build_ext]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "include-dirs = ${OPENSSLINC}" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "library-dirs = ${OPENSSLLIB}" >> ${WRKSRC}/setup.cfg

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
