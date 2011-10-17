# New ports collection makefile for:    py-transmissionrpc
# Date created:                         2009-12-03
# Whom:					Vladimir Korkodinov <newbieman@perm.raid.ru>
#
# $FreeBSD$
#

PORTNAME=	transmissionrpc
PORTVERSION=	0.8
CATEGORIES=	net-p2p python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	A Python module that communicates with Transmission through JSON-RPC

LICENSE=	MIT

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.if !defined(NOPORTDOCS)
PLIST_DIRS=	%%DOCSDIR%%
PLIST_FILES+=	%%DOCSDIR%%/README
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
