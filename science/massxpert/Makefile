# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	massxpert
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://download.tuxfamily.org/massxpert/source/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	The massXpert software for (bio)chemists

LICENSE=	GPLv3

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_GCC=	any
USES=		cmake gettext iconv tar:bzip2
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_GNOME=	glib20
USE_QT4=	corelib gui xml rcc_build qmake_build uic_build moc_build \
		svg
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
