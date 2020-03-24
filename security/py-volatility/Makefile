# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	volatility
DISTVERSION=	2.6.1-34
DISTVERSIONSUFFIX=	-g753bfa87
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced memory forensics framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distorm>=0:devel/py-distorm@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=0:textproc/py-openpyxl@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	volatilityfoundation

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	tools/*.py tools/mac/*.py

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
PORTDOCS=	AUTHORS.txt CHANGELOG.txt CREDITS.txt LEGAL.txt README.txt

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=--install-data ${DATADIR}

post-patch:
	${TOUCH} ${WRKSRC}/contrib/plugins/aspaces/__init__.py \
		${WRKSRC}/contrib/plugins/malware/__init__.py

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
