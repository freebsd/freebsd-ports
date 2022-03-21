PORTNAME=	pdfminer.six
PORTVERSION=	20211012
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	PDF parser and analyzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

CONFLICTS_INSTALL=	py??-pdfminer py??-pdfminer3k
NO_ARCH=		yes

post-extract:
	@cd ${WRKSRC} && ${MV} tools/dumppdf.py tools/dumppdf
	@cd ${WRKSRC} && ${MV} tools/pdf2txt.py tools/pdf2txt

.include <bsd.port.mk>
