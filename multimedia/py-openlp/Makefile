# $FreeBSD$

PORTNAME=	OpenLP
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Open Source Lyrics Projection

LICENSE=	GPLv2

BUILD_DEPENDS=	py*-sip>=0:${PORTSDIR}/devel/py-sip \
		py*-qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-mako>0:${PORTSDIR}/textproc/py-mako \
		py*-sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy
RUN_DEPENDS=	py*-beautifulsoup32>0:${PORTSDIR}/www/py-beautifulsoup32 \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		py*-qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		py*-phonon>=${PYQT4_VERSION}:${PORTSDIR}/multimedia/py-qt4-phonon \
		py*-sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		py*-qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		py*-qt4-opengl>=0:${PORTSDIR}/x11/py-qt4-opengl \
		py*-qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		py*-qt4-test>=0:${PORTSDIR}/devel/py-qt4-test \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet \
		py*-mako>0:${PORTSDIR}/textproc/py-mako \
		py*-enchant>0:${PORTSDIR}/textproc/py-enchant \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.6.1:${PORTSDIR}/databases/py-sqlalchemy-migrate \
		py*-sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		unoconv:${PORTSDIR}/textproc/unoconv

PYDISTUTILS_NOEGGINFO=	yes
USE_PYTHON=	2.6+
USE_PYDISTUTILS=easy_install
USE_GSTREAMER=	good bad ugly
USE_QT4=	linguist phonon-gst
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
QT_LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

NO_STAGE=	yes
pre-build:
	@${MKDIR} -p ${WRKSRC}/resources/i18n/qm
	@set -e; \
	for TSFILE in ${WRKSRC}/resources/i18n/*.ts; do \
		${QT_LRELEASE} $$TSFILE -qm ${WRKSRC}/resources/i18n/qm/`basename $$TSFILE .ts`.qm; \
	done

post-install:
	@${MKDIR} -p ${PREFIX}/share/openlp/i18n/
	@${CP} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/resources/i18n/qm/*.qm ${PREFIX}/share/openlp/i18n/
	#@${MV} ${PREFIX}/bin/openlp.pyw ${PREFIX}/bin/openlp
	@${LN} -s ${PREFIX}/bin/openlp.pyw ${PREFIX}/bin/openlp
	@${CP} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/resources/openlp.desktop ${PREFIX}/share/applications/
	@set -e; \
	for SIZE in 16x16 32x32 48x48 64x64 128x128 256x256; do \
		mkdir -p ${PREFIX}/share/icons/hicolor/$$SIZE/apps && \
		cp ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/resources/images/openlp-logo-$$SIZE.png ${PREFIX}/share/icons/hicolor/$$SIZE/apps/openlp.png; \
	done
	@${MKDIR} -p ${PREFIX}/share/icons/hicolor/scalable/apps
	@${CP} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/resources/images/openlp-logo.svg ${PREFIX}/share/icons/hicolor/scalable/apps/openlp.svg

.include <bsd.port.mk>
