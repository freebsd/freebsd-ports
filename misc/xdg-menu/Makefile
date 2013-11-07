# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	xdg-menu
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	XDG-Menu-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	XDG-Menu-${DISTVERSION}.tgz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	ROX panel applet that displays an applications menu button

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus

WRKSRC=		${WRKDIR}/XDG-Menu
DATADIR=	${PREFIX}/apps/XDG-Menu

USE_PYTHON=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	*

DESKTOP_ENTRIES="XDG-Menu" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Application;System;" false

OPTIONS_DEFINE=	ROX
ROX_DESC=	Enable ROX panel applet support

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' 's|/usr/lib|../../lib|' ${WRKSRC}/findrox.py

.if ! ${PORT_OPTIONS:MROX}
	@${REINPLACE_CMD} -i '' '/if not rox.confirm/,/sys.exit/s/^/#/' ${WRKSRC}/AppRun
	@${ECHO_MSG}
	@${ECHO_MSG} "You have not enabled ROX panel applet support"
	@${ECHO_MSG}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endif

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${CP} -r Messages .DirIcon AppInfo.xml AppRun AppletRun \
		Options.xml Messages python *.py *.pyc *.pyo ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/Help/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
