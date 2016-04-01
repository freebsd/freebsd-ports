# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pywikibot
DISTVERSION=	2.0rc1.post2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Wikipedia bot for Python

LICENSE=	MIT

RUN_DEPENDS=	${PKGNAMEPREFIX}httplib2>=0:www/py-httplib2

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	ISBN PYDOT MYSQL GOOGLE MWPARSE PILLOW
ISBN_DESC=	Support for standard numbers and codes via stdnum package
PYDOT_DESC=	Support for Graphviz via pydot module
MYSQL_DESC=	Support for MySQL via oursql module
GOOGLE_DESC=	Support for Google search
MWPARSE_DESC=	Support for MediaWiki parser
PILLOW_DESC=	Support for image processing via pillow module

ISBN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stdnum>=0:devel/py-stdnum
PYDOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oursql>=0:databases/py-oursql
GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google>=0:www/py-google
MWPARSE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mwparserfromhell>=0:textproc/py-mwparserfromhell
PILLOW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

.include <bsd.port.mk>
