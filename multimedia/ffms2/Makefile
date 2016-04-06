# $FreeBSD$

PORTNAME=	ffms2
DISTVERSION=	2.22
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	FFmpeg-based source library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	FFMS

USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-static
CPPFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
