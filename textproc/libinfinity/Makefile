PORTNAME=	libinfinity
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/gobby/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Collaborative editing library
WWW=		https://github.com/gobby/libinfinity

LICENSE=	LGPL-2.1-only
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core \
		libavahi-client.so:net/avahi-app \
		libdaemon.so:devel/libdaemon \
		libgnutls.so:security/gnutls \
		libgsasl.so:security/libgsasl \
		libharfbuzz.so:print/harfbuzz

USES=		cpe gettext gmake gnome libtool:build pathfix pkgconfig
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 intltool libxml2 pango
USE_LDCONFIG=	yes

CPE_VENDOR=	libinfinity_project

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${MV} infinoted-0.7 \
		infinoted
	@cd ${STAGEDIR}${PREFIX}/share/man/man1 && \
		${MV} infinoted-0.7.1 \
		infinoted.1

.include <bsd.port.mk>
