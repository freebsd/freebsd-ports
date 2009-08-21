# New ports collection makefile for:	qutim
# Date created:		Mon Jun 16 20:42:11 MSD 2008
# Whom:			webmaster@kibab.com
#
# $FreeBSD$
#

PORTNAME=	qutim
PORTVERSION=	0.2b
CATEGORIES=	net-im
MASTER_SITES=	http://qutim.org/download/ \
		http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutim/
DISTNAME=	qutim_${PORTVERSION}_svn326

MAINTAINER=	webmaster@kibab.com
COMMENT=	A Qt4-based lightweight ICQ client with advanced features

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui designer_build script_build network webkit xml moc_build qmake_build rcc_build uic_build
USE_XORG=	xscrnsaver

MAKE_JOBS_SAFE=	yes

USE_CMAKE=	yes
CMAKE_BUILD_TYPE=	DEBUG
CMAKE_USE_PTHREAD=	yes
CMAKE_VERBOSE=	yes
CMAKE_ARGS+=	-DUNIX:BOOL=1 -DBSD:BOOL=1

PLIST_FILES=	bin/qutim \
		include/qutim/plugininterface.h \
		include/qutim/protocolinterface.h \
		include/qutim/iconmanagerinterface.h
PLIST_DIRS=	include/qutim

WRKSRC=		${WRKDIR}/qutim

do-install:
	@${MKDIR} ${PREFIX}/include/qutim
	@${INSTALL_PROGRAM} ${WRKSRC}/qutim ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/include/qutim/plugininterface.h ${PREFIX}/include/qutim
	@${INSTALL_DATA} ${WRKSRC}/include/qutim/protocolinterface.h ${PREFIX}/include/qutim
	@${INSTALL_DATA} ${WRKSRC}/include/qutim/iconmanagerinterface.h ${PREFIX}/include/qutim
	@${STRIP_CMD} ${PREFIX}/bin/qutim

.include <bsd.port.mk>
