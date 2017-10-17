# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ring-libclient
PORTVERSION=	0.160516
PORTREVISION=	4
#DISTVERSIONPREFIX=	v
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Client library for the Ring VoIP SIP phone and IM

LICENSE=	GPLv3

LIB_DEPENDS=	libring.so:net-im/ring-daemon

USE_GITHUB=	yes
#GH_TUPLE+=	savoirfairelinux:ring-lrc:9eaac77
GH_TUPLE+=	savoirfairelinux:ring-lrc:cb5ee04

USES=		cmake compiler:c++14-lang
USE_GNOME=	glib20 gtk20 cairo gdkpixbuf2
USE_XORG=	x11 xscrnsaver
USE_GL=		gl
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

OPTIONS_DEFINE=	NLS
NLS_CMAKE_ON=	-DFREEBSD_NLS_ON:BOOL=ON
OPTIONS_SUB=	yes

.include <bsd.port.mk>
