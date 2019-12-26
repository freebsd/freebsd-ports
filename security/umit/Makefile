# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	umit
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nmap frontend developed with Python and PyGTK

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${LOCALBASE}/bin/nmap:security/nmap

NO_ARCH=	yes

USES=		gnome python:2.7 shebangfix tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	distutils
INSTALLS_ICONS=	yes
SHEBANG_FILES=	*.py umit/gui/*.py higwidgets/*.py umit/interfaceeditor/*.py \
		umit/plugin/*.py umit/core/*.py umit/merger/*.py \
		umit/interfaceeditor/selectborder/*.py

PORTDOCS=	*

DESKTOP_ENTRIES="Umit" "GUI frontend for Nmap security/port scanner" "umit" \
		"umit" "System;GTK;" ""

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e \
		's|distutils\(.command.install\) |setuptools\1 | ; \
		 s|sphinx\.main|sphinx\.build_main| ; \
		 /self.create_uninstaller()/d ; \
		 /self.pkgmaintainer/s|0|1|' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	@${LN} -sf ${PREFIX}/share/pixmaps/umit/umit_48x48.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/umit.png

.include <bsd.port.mk>
