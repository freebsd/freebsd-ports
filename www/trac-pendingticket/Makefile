# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	pendingticket
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Support for pending tickets

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/removependingplugin
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	RemovePendingStatusPlugin
PLIST_FILES=		bin/close_old_pending.py \
			bin/migrate_pending_attrib_to_status.py \
			%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
post-patch:
	cd ${WRKDIR}/${PORTNAME}plugin && ${PATCH} < ${PATCHDIR}/close_old_pending.py.patch
	${REINPLACE_CMD} -e "s,%%PYTHON%%,${PYTHON_CMD}," ${WRKDIR}/${PORTNAME}plugin/close_old_pending.py
	cd ${WRKDIR}/${PORTNAME}plugin && ${PATCH} < ${PATCHDIR}/migrate_pending_attrib_to_status.py.patch
	${REINPLACE_CMD} -e "s,%%PYTHON%%,${PYTHON_CMD}," ${WRKDIR}/${PORTNAME}plugin/migrate_pending_attrib_to_status.py

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}plugin/close_old_pending.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}plugin/migrate_pending_attrib_to_status.py ${PREFIX}/bin

.include <bsd.port.mk>
