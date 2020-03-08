# Created by: tundra
# $FreeBSD$

PORTNAME=	twander
PORTVERSION=	3.231
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.tundraware.com/Software/twander/

MAINTAINER=	twander@tundraware.com
COMMENT=	Better Filesystem Browser

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/twander-license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell no-auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python:2.7 shebangfix
SHEBANG_FILES=	twander.py
MAKE_ENV=	PYTHON_CMD="${PYTHON_CMD}"
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in READ-1ST.txt WHATSNEW.txt .twander twander.html twander.pdf twander.ps twander.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
