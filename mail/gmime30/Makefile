PORTNAME=	gmime
PORTVERSION=	3.2.7
CATEGORIES=	mail
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

LICENSE=	LGPL21

LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libidn2.so:dns/libidn2 \
		libgpg-error.so:security/libgpg-error

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}30
USES=		gettext-runtime gmake gnome iconv libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	VALA
OPTIONS_DEFAULT=	VALA
OPTIONS_SUB=	yes
VALA_DESC=	Install vala binding
VALA_BUILD_DEPENDS=	vala>=0.20:lang/vala
VALA_CONFIGURE_ENABLE=	vala

# www.freebsd.org/cgi/query-pr.cgi?pr=118092
# Rename uudecode and uuencode to gmime-* to not conflict with userland
# fix kept in case issue returns
CONFIGURE_ARGS?= \
		--program-transform-name="s/uuencode/gmime-uuencode/;s/uudecode/gmime-uudecode/;"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
