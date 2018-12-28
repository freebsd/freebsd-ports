# $FreeBSD$

PORTNAME=	slixmpp
DISTVERSION=	1.4.1
CATEGORIES=	net-im python
MASTER_SITES=	https://git.poez.io/slixmpp/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	slix-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Threadless Poezio-oriented fork of SleekXMPP using asyncio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libidn.so:dns/libidn
TEST_DEPENDS=	gpg:security/gnupg

USES=		python:3.5+
USE_PYTHON=	distutils autoplist cython

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} run_tests.py

.include <bsd.port.mk>
