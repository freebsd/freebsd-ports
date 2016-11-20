# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	volatility
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://downloads.volatilityfoundation.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced memory forensics framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}distorm>=0:devel/py-distorm \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=0:textproc/py-openpyxl

USES=		python:2 zip
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/volatility-master
DATADIR=	${PREFIX}/share/py-${PORTNAME}
PORTDOCS=	AUTHORS.txt CHANGELOG.txt CREDITS.txt LEGAL.txt README.txt
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=--install-data ${DATADIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
