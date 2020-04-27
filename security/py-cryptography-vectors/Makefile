# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptography-vectors
PORTVERSION=	2.9.2
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

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
