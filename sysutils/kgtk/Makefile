# Ports collection makefile for:	kgtk
# Date created:			Sep 13, 2007
# Whom:				Rashid N. "Citycat" Achilov <citycat4@ngs.ru>
#
# $FreeBSD$
#

PORTNAME=	kgtk
PORTVERSION=	0.9.4
PORTREVISION=	11
CATEGORIES=	sysutils kde
MASTER_SITES=	http://source.antisupport.com/kgtk/ \
		http://home.freeuk.com/cpdrummond/
DISTNAME=	KGtk-${PORTVERSION}

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Daemon to use KDE dialogs in GTK applications

SUB_FILES=	pkg-message

OPTIONS=	UNICODE "System locale is utf-8" off

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_KDEBASE_VER=3
USE_CMAKE=	yes
CMAKE_USE_PTHREAD= yes

WRKSRC=		${WRKDIR}/${DISTNAME}/build
CMAKE_SOURCE_PATH=	..

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

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's| -ldl||' ${WRKSRC}/../gtk2/CMakeLists.txt \
		${WRKSRC}/../qt3/CMakeLists.txt ${WRKSRC}/../qt4/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' ${WRKSRC}/../qt3/kqt3-wrapper.cmake \
		${WRKSRC}/../gtk2/kgtk2-wrapper.cmake ${WRKSRC}/../qt4/kqt4-wrapper.cmake \
		${WRKSRC}/../mangled.sh ${WRKSRC}/../kdialogd-wrapper ${WRKSRC}/../kgtk-wrapper
	@${CP} ${PATCHDIR}/ru.po ${WRKSRC}/../kdialogd3/po/

post-configure:
	@${REINPLACE_CMD} -e '/pofiles/ s|\.\./||' \
	${WRKSRC}/kdialogd3/po/CMakeFiles/pofiles.dir/build.make

post-install:
	@${CAT} ${PKGMESSAGE}
	
.include <bsd.port.post.mk>
