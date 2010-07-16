# New ports collection makefile for:	py-openlp
# Date created:		2010-01-19
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OpenLP
PORTVERSION=	1.9.2.1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/openlp/openlp/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Open Source Lyrics Projection

LICENSE=	GPLv2

BUILD_DEPENDS=	py*-sip>=0:${PORTSDIR}/devel/py-sip \
		py*-qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy
RUN_DEPENDS=	py*-beautifulsoup<3.1:${PORTSDIR}/www/py-beautifulsoup30 \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		py*-phonon>=${PYQT4_VERSION}:${PORTSDIR}/multimedia/py-qt4-phonon \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet

PLIST_SUB+=	VERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

USE_PYTHON=		2.5+
USE_PYTHON_PREFIX=	yes
USE_GSTREAMER=		good
NO_BUILD=		yes

do-install:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install

post-install:
	@${MV} ${PREFIX}/bin/openlp.pyw ${PREFIX}/bin/openlp

.include <bsd.port.mk>
