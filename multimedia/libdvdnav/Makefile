PORTNAME=	libdvdnav
DISTVERSION=	7.0.0
CATEGORIES=	multimedia

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Videolan version of the libdvdnav project
WWW=		https://www.videolan.org/developers/libdvdnav.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread

USES=		meson pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org/
GL_ACCOUNT=	videolan

PORTDOCS=	AUTHORS COPYING ChangeLog README.md TODO

MESON_ARGS=	-Ddefault_library=shared

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
