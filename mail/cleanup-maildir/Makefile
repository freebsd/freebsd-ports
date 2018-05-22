# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cleanup-maildir
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	mail python

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Script for cleaning up mails in Maildir folders based on arival date

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graph-core>=${PORTVERSION}:graphics/py-graph-core@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes

GH_ACCOUNT=	ehaupt

SHEBANG_FILES=	cleanup-maildir.py
PLIST_FILES=	bin/cleanup-maildir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cleanup-maildir.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
