# $FreeBSD$

PORTNAME=	libndi
PORTVERSION=	g20200630
CATEGORIES=	multimedia net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, open-source library done to interact with NDI streams

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libmicrodns.so:dns/libmicrodns

USES=		meson pkgconfig

USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	jbk
GL_COMMIT=	c14b40caafb26a02249f062e7f907ceaa53c1b74

PLIST_FILES=	bin/ndi \
		include/libndi.h \
		lib/libndi.so \
		lib/libndi.so.0 \
		lib/libndi.so.0.0.1

.include <bsd.port.mk>
