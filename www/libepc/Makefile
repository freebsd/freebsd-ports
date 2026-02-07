PORTNAME=	libepc
PORTVERSION=	0.4.6
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Easy Publish and Consume library
WWW=		https://live.gnome.org/libepc/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:misc/libuuid \
		libfribidi.so:converters/fribidi \
		libsoup-2.4.so:devel/libsoup \
		libgnutls.so:security/gnutls \
		libavahi-common.so:net/avahi-app \
		libavahi-ui-gtk3.so:net/avahi-gtk3

USES=		compiler gettext gmake gnome libtool pathfix pkgconfig \
		tar:xz
USE_GNOME=	gnomeprefix cairo gdkpixbuf gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' \
		${WRKSRC}/examples/simple-publisher.c
.endif

.include <bsd.port.post.mk>
