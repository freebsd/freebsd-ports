# $FreeBSD$

PORTNAME=	sunflower
DISTVERSION=	0.3-61
PORTREVISION=	1
CATEGORIES=	x11-fm python
MASTER_SITES=	http://sunflower-fm.org/pub/

MAINTAINER=	bsd@abinet.ru
COMMENT=	Twin-panel file manager

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notify>0:devel/py-notify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.2.0:devel/py-dbus@${PY_FLAVOR}

WRKSRC=		${WRKDIR}/Sunflower

USES=		desktop-file-utils gettext python:2.7 shebangfix tar:tgz
USE_GNOME=	gtk20 pygtk2 pygobject
NO_ARCH=	yes
INSTALLS_ICONS=	yes
SHEBANG_FILES=	Sunflower.py

OPTIONS_DEFINE=	VTE
OPTIONS_DEFAULT=VTE

VTE_DESC=	Use VTE terminal widget
VTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vte>0:x11-toolkits/py-vte@${PY_FLAVOR}

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/Sunflower.py

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}
	${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} application ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} translations ${STAGEDIR}${DATADIR} \
		"! -name *\.po*"
	${INSTALL_SCRIPT}  ${WRKSRC}/Sunflower.py \
		${STAGEDIR}${PREFIX}/bin/sunflower
	${INSTALL_DATA} ${WRKSRC}/images/sunflower.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/Sunflower.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
