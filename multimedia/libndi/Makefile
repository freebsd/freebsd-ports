PORTNAME=	libndi
PORTVERSION=	g20250811
CATEGORIES=	multimedia net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, open-source library done to interact with NDI streams
WWW=		https://code.videolan.org/jbk/libndi

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmicrodns.so:dns/libmicrodns

USES=		meson pkgconfig

USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	jbk
GL_TAGNAME=	930234549f96bcf7442795180f8d1fb43ed23af1

.include <bsd.port.mk>
