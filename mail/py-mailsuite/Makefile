PORTNAME=	mailsuite
DISTVERSION=	1.9.16
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python package to simplify receiving, parsing, and sending email
WWW=		https://github.com/seanthegeek/mailsuite

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.0.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=2020.1.16:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imapclient>=2.1.0:mail/py-imapclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mail-parser>=3.14.0:mail/py-mail-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffix2>=2.20190812:dns/py-publicsuffix2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	${RM} ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
