PORTNAME=	gmime
PORTVERSION=	2.6.23
PORTREVISION=	4
CATEGORIES?=	mail
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	26

MAINTAINER?=	bofh@FreeBSD.org
COMMENT?=	Library (written in C) for parsing and creating messages using MIME
WWW=		https://spruce.sourceforge.net/gmime/

LICENSE=	LGPL21

LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error

USES=		gettext-runtime gmake gnome iconv libtool localbase pathfix pkgconfig tar:xz

SLAVEDIRS=	mail/gmime26-sharp

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}26
USE_GNOME+=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GINTRO VAPI
OPTIONS_SUB=	yes
GINTRO_DESC=	Install GObject Introspection data
GINTRO_BUILD_DEPENDS=	gobject-introspection>=0.6.8:devel/gobject-introspection
GINTRO_RUN_DEPENDS=	gobject-introspection>=0.6.8:devel/gobject-introspection
GINTRO_CONFIGURE_ENABLE=introspection
VAPI_USES=		vala:build
VAPI_CONFIGURE_ENABLE=	vala
VAPI_IMPLIES=	GINTRO

# www.freebsd.org/cgi/query-pr.cgi?pr=118092
# Rename uudecode and uuencode to gmime-* to not conflict with userland
# fix kept in case issue returns
CONFIGURE_ARGS?=--enable-mono=no \
		--program-transform-name="s/uuencode/gmime-uuencode/;s/uudecode/gmime-uudecode/;"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
