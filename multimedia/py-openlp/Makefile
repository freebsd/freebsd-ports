# New ports collection makefile for:	py-openlp
# Date created:		2010-01-19
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OpenLP
PORTVERSION=	1.9.8
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
RUN_DEPENDS=	py*-beautifulsoup<3.1:${PORTSDIR}/www/py-beautifulsoup30 \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		py*-phonon>=${PYQT4_VERSION}:${PORTSDIR}/multimedia/py-qt4-phonon \
		py*-sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		py*-qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet \
		py*-mako>0:${PORTSDIR}/textproc/py-mako \
		py*-migrate>=0:${PORTSDIR}/databases/py-migrate \
		py*-sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

PYDISTUTILS_NOEGGINFO=	yes
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
USE_GSTREAMER=		good
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	@${LN} -s ${PREFIX}/bin/openlp.pyw ${PREFIX}/bin/openlp
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/openlp-remoteclient.py \
		${PREFIX}/bin/openlp-remoteclient.py

.include <bsd.port.mk>
