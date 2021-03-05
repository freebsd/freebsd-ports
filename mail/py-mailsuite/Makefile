# $FreeBSD$

PORTNAME=	mailsuite
PORTVERSION=	1.6.1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python package to simplify receiving, parsing, and sending email

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imapclient>=2.1.0:mail/py-imapclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mail-parser>=3.11.0:mail/py-mail-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython2>=2.0.0:dns/py-dnspython2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=2020.1.16:textproc/py-html2text@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
