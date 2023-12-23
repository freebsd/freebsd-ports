PORTNAME=	gtkspell3
PORTVERSION=	3.0.10
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	SF/gtkspell/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK 3 spell checking component
WWW=		https://gtkspell.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi
RUN_DEPENDS=	iso-codes>0:misc/iso-codes

USES=		gettext gmake gnome localbase libtool pathfix pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
