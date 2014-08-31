# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	umit
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nmap frontend developed with Python and PyGTK

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap

NO_ARCH=	yes

USES=		python tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	distutils
INSTALLS_ICONS=	yes

PORTDOCS=	*

DESKTOP_ENTRIES="Umit" "GUI frontend for Nmap security/port scanner" "umit" \
		"umit" "System;GTK;" ""

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx

post-patch:
	@${REINPLACE_CMD} -e \
		's|distutils\(.command.install\) |setuptools\1 | ; \
		 /self.create_uninstaller()/d ; \
		 /self.pkgmaintainer/s|0|1|' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	@${LN} -sf ${DATADIR}/pixmaps/umit_48x48.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/umit.png

.include <bsd.port.mk>
