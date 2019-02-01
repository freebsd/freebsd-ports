# $FreeBSD$

PORTNAME=	pdfminer.six
PORTVERSION=	20170720
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	PDF parser and analyzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR}

USES=		python shebangfix dos2unix
USE_PYTHON=	distutils concurrent autoplist
SHEBANG_FILES=	tools/dumppdf.py tools/pdf2txt.py tools/latin2ascii.py
DOS2UNIXGLOB=	*.py

CONFLICTS_INSTALL=	py??-pdfminer-* py??-pdfminer3k-*
NO_ARCH=		yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
