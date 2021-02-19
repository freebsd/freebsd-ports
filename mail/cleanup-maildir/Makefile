# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cleanup-maildir
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	mail python

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Script for cleaning up mails in Maildir folders based on arival date

LICENSE=	AS-IS
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraph>=0.2.1:graphics/py-pygraph@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt
SHEBANG_FILES=	cleanup-maildir.py
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/cleanup-maildir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cleanup-maildir.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
