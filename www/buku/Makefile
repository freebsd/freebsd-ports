# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buku
PORTVERSION=	4.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Powerful command-line bookmark manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.2.3:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.0.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.23:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/buku.1.gz

post-extract:
	@${RM} -fr ${WRKSRC}/bukuserver

post-install:
	${INSTALL_MAN} ${WRKSRC}/buku.1 ${STAGEDIR}${MANPREFIX}/share/man/man1

.include <bsd.port.mk>
