# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freefilesync
DISTVERSION=	9.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.freefilesync.org/download/ \
		https://www.freefilesync.org/archive/
DISTNAME=	FreeFileSync_${PORTVERSION}_Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backup software to synchronize files and folders

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/include/zenxml/xml.h:textproc/zenxml
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify

FETCH_ARGS=	--user-agent=firefox

WRKSRC=		${WRKDIR}/FreeFileSync/Source

USES=		compiler:c++14-lang dos2unix gmake pkgconfig zip
USE_WX=		3.0+
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
DOS2UNIX_WRKSRC=	${WRKDIR}
DOS2UNIX_GLOB=	*.cpp *.h

post-patch:
	@${REINPLACE_CMD} -e 's/wx-config/$${WX_CONFIG:T}/' \
		-e 's,g++,$${CXX},' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<sys/vfs.h>|<sys/mount.h>|' \
		${WRKDIR}/zen/file_access.cpp
	@${REINPLACE_CMD} -e 's|WEXITSTATUS||' ${WRKDIR}/zen/shell_execute.h
	@${REINPLACE_CMD} -e 's| noexcept;|;|' ${WRKDIR}/zen/scope_guard.h

.include <bsd.port.mk>
