# $FreeBSD$

PORTNAME=	OpenLP
PORTVERSION=	2.4.6
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	https://get.openlp.org/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Lyrics Projection

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=0:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		unoconv:textproc/unoconv

USES=		desktop-file-utils gnome pyqt:5 python:3.4+ qt:5
USE_PYQT=	core_run gui_run multimedia_run network_run opengl_run printsupport_run \
	       	sip_run svg_run webkit_run webkitwidgets_run widgets_run
USE_PYTHON=	distutils autoplist
USE_QT=		linguist_build
USE_GSTREAMER=	good bad ugly

INSTALLS_ICONS=	yes
NO_ARCH=	yes

ICON_SIZES=	16x16 32x32 48x48 64x64 128x128 256x256

post-patch:
	@${REINPLACE_CMD} -e 's|openlp\.py|OpenLP|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -Ee 's|^(Exec=)openlp|\1OpenLP|' ${WRKSRC}/resources/openlp.desktop
	@(cd ${WRKSRC} && ${MV} openlp.py OpenLP)

post-build:
	@${RM} -r ${WRKSRC}/build/lib/tests
	@${MKDIR} ${WRKSRC}/resources/i18n/qm
	@set -e; \
	for TSFILE in ${WRKSRC}/resources/i18n/*.ts; do \
		${LRELEASE} $$TSFILE -qm ${WRKSRC}/resources/i18n/qm/`basename $$TSFILE .ts`.qm; \
	done

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openlp/i18n
	${INSTALL_DATA} ${WRKSRC}/resources/i18n/qm/*.qm ${STAGEDIR}${PREFIX}/share/openlp/i18n
	${INSTALL_DATA} ${WRKSRC}/resources/openlp.desktop ${STAGEDIR}${PREFIX}/share/applications

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/images/openlp-logo-${s}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/openlp.png
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/resources/images/openlp-logo.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/openlp.svg

.include <bsd.port.mk>
