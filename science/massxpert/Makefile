# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	massxpert
PORTVERSION=	3.4.0
CATEGORIES=	science
MASTER_SITES=	http://download.tuxfamily.org/massxpert/source/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	The massXpert software for (bio)chemists

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

LICENSE=	GPLv3

USE_GCC=	any
USE_BZIP2=	yes
USES=		cmake gettext iconv
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_GNOME=	glib20
USE_QT4=	corelib gui xml rcc_build qmake_build uic_build moc_build \
		svg
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
MAN7=		massxpert-data.7
MAN1=		massxpert.1

.include <bsd.port.mk>
