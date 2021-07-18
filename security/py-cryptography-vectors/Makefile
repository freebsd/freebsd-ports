# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cryptography-vectors
PORTVERSION=	3.3.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cryptography_vectors-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test vectors for the cryptography package

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
