# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdg-menu
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	XDG-Menu-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	XDG-Menu-${DISTVERSION}.tgz

MAINTAINER=	horia@racoviceanu.com
COMMENT=	ROX panel applet that displays an applications menu button

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Help/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus

WRKSRC=		${WRKDIR}/XDG-Menu
DATADIR=	${PREFIX}/apps/XDG-Menu

USES=		python
INSTALLS_ICONS=	yes
NO_ARCH=	yes

PORTDOCS=	*

DESKTOP_ENTRIES="XDG-Menu" "" ${PORTNAME} \
		"${PORTNAME}" "System;" ""

OPTIONS_DEFINE=	DOCS ROX
ROX_DESC=	Enable ROX panel applet support

SUB_FILES=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -i '' 's|/usr/lib|../../lib|' ${WRKSRC}/findrox.py

post-patch-ROX-off:
	@${REINPLACE_CMD} -i '' '/if not rox.confirm/,/sys.exit/s/^/#/' \
		${WRKSRC}/AppRun
	@${ECHO_MSG}
	@${ECHO_MSG} "You have not enabled ROX panel applet support"
	@${ECHO_MSG}
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${CP} -r Messages .DirIcon AppInfo.xml AppRun AppletRun \
		Options.xml Messages python *.py *.pyc *.pyo ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/Help/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
