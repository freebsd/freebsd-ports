# New ports collection makefile for:    gtk-qt-engine
# Date created:                         23 February 2004
# Whom:                                 Danny Pansters <danny@ricin.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt-engine
PORTVERSION=	0.8
PORTREVISION=	# zero
CATEGORIES=	x11-themes
MASTER_SITES=	http://gtk-qt.ecs.soton.ac.uk/files/${PORTVERSION}/ \
		http://freebsd.ricin.com/ports/distfiles/

MAINTAINER=	danny@ricin.com
COMMENT=	GTK-QT Theme Engine allows GTK2 apps to use QT/KDE themes

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_QT_VER=	3
USE_KDEBASE_VER=3
HAS_CONFIGURE=	yes

OPTIONS=	LIBBONOBOUI "Install libbonoboui if missing" off

WRKSRC=		${WRKDIR}/${PORTNAME}
CMAKE?=		${LOCALBASE}/bin/cmake
CMAKE_ARGS=	-DCMAKE_C_COMPILER:STRING="${CC}"\
		-DCMAKE_CXX_COMPILER:STRING="${CXX}"\
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}"\
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITH_LIBBONOBOUI)
USE_GNOME+=	libbonoboui
.endif

do-configure:
	cd ${WRKSRC} && ${CMAKE} ${CMAKE_ARGS} .

.include <bsd.port.post.mk>
