# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	massxpert
PORTVERSION=	3.4.0
PORTREVISION=	9
CATEGORIES=	science
MASTER_SITES=	http://download.tuxfamily.org/massxpert/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	massXpert software for (bio)chemists

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_GCC=	any
USES=		cmake gettext tar:bzip2
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_GNOME=	glib20
USE_QT4=	corelib gui xml rcc_build qmake_build uic_build moc_build \
		svg
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
