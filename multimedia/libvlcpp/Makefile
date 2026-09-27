PORTNAME=	libvlcpp
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ bindings for libvlc, VLC mediaplayer library
WWW=		https://code.videolan.org/videolan/libvlcpp

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vlc>0:multimedia/vlc
RUN_DEPENDS=	${LOCALBASE}/include/vlc/vlc.h:multimedia/vlc

USES=		meson compiler:c++11-lang pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan

NO_ARCH=	yes

.include <bsd.port.mk>
