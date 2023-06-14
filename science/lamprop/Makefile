PORTNAME=	lamprop
PORTVERSION=	2020.12.28
CATEGORIES=	science python

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Calculates properties of fiber reinforced composites
WWW=		https://rsmith.home.xs4all.nl/software/lamprop.html

LICENSE=	BSD2CLAUSE

USES=		python shebangfix
SHEBANG_FILES=	setup.py
USE_GITHUB=	yes
GH_ACCOUNT=	rsmith-nl

NO_ARCH=	yes

PORTDOCS=	lamprop-manual.pdf README.rst
PLIST_FILES=	bin/lamprop

OPTIONS_DEFINE=	DOCS GUI

GUI_DESC=		Tkinter GUI for lamprop
GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
GUI_PLIST_FILES=	bin/lamprop-gui

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lamprop ${STAGEDIR}${PREFIX}/bin

do-install-GUI-on:
	${INSTALL_SCRIPT} ${WRKSRC}/lamprop-gui ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/lamprop-manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
