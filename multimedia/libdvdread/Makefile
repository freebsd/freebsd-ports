# Created by: Marc van Woerkom <3d@FreeBSD.org>

PORTNAME=	libdvdread
PORTVERSION=	6.1.2
CATEGORIES=	multimedia
MASTER_SITES=	https://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Videolan version of the libdvdread project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig tar:bz2
USE_CSTD=	c99
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO

OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		DVDCSS
OPTIONS_RADIO_DVDCSS=	DVDCSS_DLOPEN DVDCSS_LINK
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS_DLOPEN
.endif

DVDCSS_DLOPEN_DESC=	Use library via dlopen() function (recommended)
# XXX DVDCSS version hardcoded in src/dvd_input.c
DVDCSS_DLOPEN_LIB_DEPENDS=	libdvdcss.so.2:multimedia/libdvdcss

DVDCSS_LINK_DESC=	Link with library
DVDCSS_LINK_LIB_DEPENDS=	libdvdcss.so.2:multimedia/libdvdcss
DVDCSS_LINK_USES=		localbase
DVDCSS_LINK_CONFIGURE_WITH=	libdvdcss

.include <bsd.port.mk>
