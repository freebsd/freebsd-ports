PORTNAME=	fig2dev
PORTVERSION=	3.2.9a
CATEGORIES=	print
MASTER_SITES=	SF/mcj/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools to convert Xfig .fig files
WWW=		https://en.wikipedia.org/wiki/Xfig

LICENSE=	fig2dev
LICENSE_NAME=	fig2dev public license
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	ppmtogif:graphics/netpbm

USES=		alias cpe ghostscript:run iconv localbase:ldflags tar:xz xorg
USE_XORG=	xpm

CPE_VENDOR=	xfig_project

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-transfig \
		GSEXE=gs
CFLAGS+=	-Wno-return-type

CONFLICTS_INSTALL=	transfig

.include <bsd.port.mk>
