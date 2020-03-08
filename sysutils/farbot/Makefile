# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	farbot
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	FreeBSD Automated Release Bot

LICENSE=	BSD3CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	threerings
GH_PROJECT=	farbot
GH_TAGNAME=	c824009

USES=		python:2.7
USE_PYTHON=	distutils autoplist
PYDISTUTILS_PKGNAME=	farb
PYDISTUTILS_PKGVERSION=	0.1
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/farbot.conf ${STAGEDIR}${PREFIX}/etc/farbot.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/xhtml
	${INSTALL_DATA} ${WRKSRC}/docs/xhtml/* ${STAGEDIR}${DOCSDIR}/xhtml

.include <bsd.port.mk>
