PORTNAME=	libvlcpp
DISTVERSION=	0.1.0.20210319
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ bindings for libvlc, VLC mediaplayer library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vlc>0:multimedia/vlc
RUN_DEPENDS=	${LOCALBASE}/include/vlc/vlc.h:multimedia/vlc

USES=		autoreconf compiler:c++11-lang gmake pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan
GL_COMMIT=	17e622c6a23f685a60451e9611d50e361cee2278

GNU_CONFIGURE=	yes

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
