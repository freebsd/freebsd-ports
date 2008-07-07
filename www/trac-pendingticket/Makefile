# New ports collection makefile for: trac-pendingticket
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pendingticket
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Support for pending tickets

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/removependingplugin
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-patch:
	cd ${WRKDIR}/${PORTNAME}plugin && ${PATCH} < ${PATCHDIR}/close_old_pending.py.patch
	${REINPLACE_CMD} -e "s,%%PYTHON%%,${PYTHON_CMD}," ${WRKDIR}/${PORTNAME}plugin/close_old_pending.py

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}plugin/close_old_pending.py ${PREFIX}/bin

.include <bsd.port.mk>
