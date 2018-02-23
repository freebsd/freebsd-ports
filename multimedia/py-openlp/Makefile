# $FreeBSD$

PORTNAME=	OpenLP
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Lyrics Projection

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0.13:databases/py-sqlalchemy10@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:www/py-beautifulsoup32@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0.13:databases/py-sqlalchemy10@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.6.1:databases/py-sqlalchemy-migrate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${FLAVOR} \
		unoconv:textproc/unoconv

USES=		desktop-file-utils pyqt:4 python:2.7
USE_PYQT=	core gui \
		network_run opengl_run phonon_run svg_run test_run webkit_run
USE_PYTHON=	distutils autoplist
USE_GSTREAMER=	good bad ugly
USE_QT4=	linguist phonon-gst
QT_LRELEASE=	${LRELEASE}
NO_ARCH=	yes

pre-build:
	@${RM} ${WRKSRC}/resources/__init__.py
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
