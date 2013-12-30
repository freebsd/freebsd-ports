# Created by: Thinker K.F. Li <thinker@cowboy.branda.to>
# $FreeBSD$

PORTNAME=	GinGin
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hybrid of WIKI and BLOG system

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mez_xml/__init__.py:${PORTSDIR}/devel/py-mez_xml
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/fcgi.py:${PORTSDIR}/www/py-fcgi

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
