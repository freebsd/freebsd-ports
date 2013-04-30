# Created by: Rashid N. "Citycat" Achilov <citycat4@ngs.ru>
# $FreeBSD$

PORTNAME=	kgtk
PORTVERSION=	0.9.4
PORTREVISION=	12
CATEGORIES=	sysutils kde
MASTER_SITES=	http://source.antisupport.com/kgtk/ \
		http://home.freeuk.com/cpdrummond/
DISTNAME=	KGtk-${PORTVERSION}

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Daemon to use KDE dialogs in GTK applications

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	UNICODE

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_KDEBASE_VER=3
USES=		cmake

WRKSRC=		${WRKDIR}/${DISTNAME}/build
CMAKE_SOURCE_PATH=	..

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ! ${PORT_OPTIONS:MUNICODE}
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

.include <bsd.port.mk>
