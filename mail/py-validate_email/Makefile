# $FreeBSD$

PORTNAME=	validate_email
DISTVERSION=	1.3
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Verifies if an email address is valid and really exists

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

# If the default version (2.7) of Python is used, use package py-dns
MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dns>0:dns/py-dns@${PY_FLAVOR}

RUN_DEPENDS=	${MY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

# If Python 3+ is used then use package py-py3dns instead
.if ${PYTHON_MAJOR_VER} == "3"
MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py3dns>0:dns/py-py3dns@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
