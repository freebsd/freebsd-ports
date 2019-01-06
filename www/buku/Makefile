# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buku
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Powerful command-line bookmark manager

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.3.4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

GH_ACCOUNT=	jarun
GH_PROJECT=	Buku

PLIST_FILES=	man/man1/buku.1.gz

post-extract:
	@${RM} -rf ${WRKSRC}/bukuserver

post-install:
	${INSTALL_MAN} ${WRKSRC}/buku.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
