# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	c++-gtk-utils
PORTVERSION=	2.2.15
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/cxx-gtk-utils/cxx-gtk-utils/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight library for programming GTK+ programs

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gettext-runtime gnome libtool pathfix \
		pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	configure-gtk2
CONFIGURE_ARGS=		--docdir=${DOCSDIR}

PORTDOCS=	*

LIBVERSION=	0.2.0
PLIST_SUB=	LIBVERSION=${LIBVERSION}

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_CONFIGURE_ON=	--enable-debug

post-configure:
	@${REINPLACE_CMD} '/^SUBDIRS/ s|tests||' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcxx-gtk-utils-2-2.2.so.${LIBVERSION}

.include <bsd.port.mk>
