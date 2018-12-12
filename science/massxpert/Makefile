# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	massxpert
PORTVERSION=	3.4.0
PORTREVISION=	12
CATEGORIES=	science
MASTER_SITES=	http://download.tuxfamily.org/massxpert/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	massXpert software for (bio)chemists

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_GCC=	any
USES=		cmake gettext qt:4 tar:bzip2
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_GNOME=	glib20
USE_QT=		corelib gui xml rcc_build qmake_build uic_build moc_build \
		svg
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
