# Ports collection makefile for:	kgtk
# Date created:			Sep 13, 2007
# Whom:				Rashid N. "Citycat" Achilov <citycat4@ngs.ru>
#
# $FreeBSD$
#

PORTNAME=	kgtk
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	http://source.antisupport.com/kgtk/ \
		http://home.freeuk.com/cpdrummond/
DISTNAME=	KGtk-${PORTVERSION}

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Daemon to use KDE dialogs in GTK applications

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

SUB_FILES=	pkg-message

OPTIONS=	UNICODE "System locale is utf-8" off

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_KDEBASE_VER=3

CMAKE_PREFIX=	${LOCALBASE}
CMAKE_BUILD_DIR=build3
BUILD_WRKSRC=	${WRKSRC}/${CMAKE_BUILD_DIR}
INSTALL_WRKSRC=	${WRKSRC}/${CMAKE_BUILD_DIR}

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_UNICODE)
EXTRA_PATCHES+=	${PATCHDIR}/opt-patch-kgtk-wrapper \
		${PATCHDIR}/opt-patch-gtk2__kgtk2-wrapper.cmake
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -ldl||' ${WRKSRC}/gtk2/CMakeLists.txt ${WRKSRC}/qt3/CMakeLists.txt ${WRKSRC}/qt4/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' ${WRKSRC}/mangled.sh
	@${CP} ${PATCHDIR}/ru.po ${WRKSRC}/kdialogd3/po/
pre-configure:
	@${MKDIR} ${WRKSRC}/${CMAKE_BUILD_DIR}

do-configure:
	@cd ${WRKSRC}/${CMAKE_BUILD_DIR} && \
		${CMAKE_PREFIX}/bin/cmake .. \
		-DCMAKE_INSTALL_DIR=${PREFIX} \
		-DQT_INCLUDE_DIR=${QT_PREFIX}/include \
		-DCMAKE_CXX_FLAGS=-I${LOCALBASE}/include \
		-DCMAKE_EXE_LINKER_FLAGS=${PTHREAD_LIBS} \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
