# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cleanup-maildir
PORTVERSION=	0.1.0.2016010801
CATEGORIES=	mail python
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Script for cleaning up mails in Maildir folders based on arival date

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graph-core>=${PORTVERSION}:graphics/py-graph-core

USES=		python shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	cleanup-maildir.py
PLIST_FILES=	bin/cleanup-maildir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cleanup-maildir.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
