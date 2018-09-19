# $FreeBSD$

PORTNAME=	ufal.udpipe
PORTVERSION=	1.2.0.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to UDPipe library for parsing universal treebanks

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips64=	Only little endian systems are supported!
BROKEN_powerpc64=	Only little endian systems are supported!

USES=		compiler:c++11-lang python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
