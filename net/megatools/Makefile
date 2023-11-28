PORTNAME=	megatools
PORTVERSION=	1.11.1.20230212
CATEGORIES=	net
MASTER_SITES=	https://megatools.megous.com/builds/

MAINTAINER=	max@kostikov.co
COMMENT=	Command line tools for MEGA.NZ cloud drive
WWW=		https://megatools.megous.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		compiler:c11 gettext-runtime gmake gnome libtool pathfix \
		pkgconfig ssl meson
USE_GNOME=	glib20

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS MANPAGES SYMLINKS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			db2x_manxml:textproc/docbook2X
MANPAGES_MESON_TRUE=	man

SYMLINKS_DESC=		Create symlinks for old commands
SYMLINKS_MESON_TRUE=	symlinks

.include <bsd.port.mk>
