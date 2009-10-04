# New ports collection makefile for:	GinGin
# Date created:		2008-02-26
# Whom:			Thinker K.F. Li <thinker@cowboy.branda.to>
#
# $FreeBSD$
#

PORTNAME=	GinGin
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hybrid of WIKI and BLOG system

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mez_xml/__init__.py:${PORTSDIR}/devel/py-mez_xml
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/fcgi.py:${PORTSDIR}/www/py-fcgi

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
