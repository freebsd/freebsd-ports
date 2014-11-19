# $FreeBSD$

PORTNAME=	OpenLP
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Open Source Lyrics Projection

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-phonon>=0:${PORTSDIR}/multimedia/py-qt4-phonon \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-opengl>=0:${PORTSDIR}/x11/py-qt4-opengl \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-test>=0:${PORTSDIR}/devel/py-qt4-test \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}enchant>0:${PORTSDIR}/textproc/py-enchant \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.6.1:${PORTSDIR}/databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		unoconv:${PORTSDIR}/textproc/unoconv

USES=		desktop-file-utils python
USE_PYTHON=	distutils autoplist
USE_GSTREAMER=	good bad ugly
USE_QT4=	linguist phonon-gst
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
QT_LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

pre-build:
	@${RM} -f ${WRKSRC}/resources/__init__.py
	@${MKDIR} ${WRKSRC}/resources/i18n/qm
	@set -e; \
	for TSFILE in ${WRKSRC}/resources/i18n/*.ts; do \
		${QT_LRELEASE} $$TSFILE -qm ${WRKSRC}/resources/i18n/qm/`basename $$TSFILE .ts`.qm; \
	done

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openlp/i18n
	${INSTALL_DATA} ${WRKSRC}/resources/i18n/qm/*.qm ${STAGEDIR}${PREFIX}/share/openlp/i18n
	${LN} -sf openlp.pyw ${STAGEDIR}${PREFIX}/bin/openlp
	${INSTALL_DATA} ${WRKSRC}/resources/openlp.desktop ${STAGEDIR}${PREFIX}/share/applications
	set -e; \
	for SIZE in 16x16 32x32 48x48 64x64 128x128 256x256; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$$SIZE/apps && \
		${INSTALL_DATA} ${WRKSRC}/resources/images/openlp-logo-$$SIZE.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/$$SIZE/apps/openlp.png; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/resources/images/openlp-logo.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/openlp.svg

.include <bsd.port.mk>
