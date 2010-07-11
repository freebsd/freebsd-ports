# New ports collection makefile for:	portrac
# Date created:				12 Sep 2009
# Whom:					mgp
#
# $FreeBSD$
#

PORTNAME=	portrac
PORTVERSION=	0.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://e-soul.org/distfiles/ \
		http://home.e-soul.org/~mgp/distfiles/

MAINTAINER=	mgp@e-soul.org
COMMENT=	A simple GUI tool for tracking port updates

PLIST_FILES=	bin/portrac \
		share/portrac/portrac.png \
		share/portrac/up-to-date.png \
		share/portrac/updates-available.png

PLIST_DIRS=	share/portrac

USE_BZIP2=	yes

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build

do-configure:
		@cd ${WRKDIR}/${DISTNAME} && ${QMAKE} portrac.pro

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/portrac ${PREFIX}/bin && \
		${MKDIR} ${DATADIR} && \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.png ${DATADIR}

.include <bsd.port.mk>
