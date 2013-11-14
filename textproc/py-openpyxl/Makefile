# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpyxl
PORTVERSION=	1.7.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library to read/write Excel 2007 xlsx/xlsm files

LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	AUTHORS README

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
