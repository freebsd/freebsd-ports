PORTNAME=	libdvdread
DISTVERSION=	7.0.0
CATEGORIES=	multimedia

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Videolan version of the libdvdread project
WWW=		https://www.videolan.org/developers/libdvdnav.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org/
GL_ACCOUNT=	videolan

PORTDOCS=	AUTHORS COPYING NEWS README.md TODO

MESON_ARGS=	-Ddefault_library=shared

OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		DVDCSS
OPTIONS_RADIO_DVDCSS=	DVDCSS_DLOPEN DVDCSS_LINK
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS_DLOPEN
.endif

DVDCSS_DLOPEN_DESC=	Use library via dlopen() function (recommended)
DVDCSS_LINK_DESC=	Link with library

# XXX DVDCSS version hardcoded in src/dvd_input.c
DVDCSS_DLOPEN_LIB_DEPENDS=	libdvdcss.so.2:multimedia/libdvdcss

DVDCSS_LINK_LIB_DEPENDS=	libdvdcss.so.2:multimedia/libdvdcss
DVDCSS_LINK_MESON_ENABLED=	libdvdcss

.include <bsd.port.mk>
