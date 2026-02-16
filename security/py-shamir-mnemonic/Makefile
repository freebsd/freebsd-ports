PORTNAME=	shamir-mnemonic
DISTVERSION=	0.3.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	shamir_mnemonic-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Implementation of SLIP-0039 Shamir mnemonic secret sharing
WWW=		https://pypi.org/project/shamir-mnemonic/ \
		https://github.com/trezor/python-shamir-mnemonic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8,<9:devel/py-click@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
