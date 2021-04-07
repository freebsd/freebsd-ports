PORTNAME=	ufal.udpipe
PORTVERSION=	1.2.0.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to UDPipe library for parsing universal treebanks

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		mips mips64 powerpc powerpc64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	Only little endian systems are supported!

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
