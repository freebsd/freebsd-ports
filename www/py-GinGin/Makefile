# Created by: Thinker K.F. Li <thinker@cowboy.branda.to>
# $FreeBSD$

PORTNAME=	GinGin
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hybrid of WIKI and BLOG system

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mez_xml/__init__.py:devel/py-mez_xml
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/fcgi.py:www/py-fcgi

USES=		python:2 shebangfix
SHEBANG_FILES=	GinGin/data/config.py.example
python_OLD_CMD=	"env python"
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
