# $FreeBSD$

PORTNAME=	mailsuite
PORTVERSION=	1.6.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python package to simplify receiving, parsing, and sending email

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.13.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imapclient>=2.1.0:mail/py-imapclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mail-parser>=3.11.0:mail/py-mail-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=2020.1.16:textproc/py-html2text@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
