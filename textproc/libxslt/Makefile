PORTNAME=	libxslt
DISTVERSION=	1.1.43
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML stylesheet transformation library
WWW=		https://gitlab.gnome.org/GNOME/libxslt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Copyright

DEPRECATED=	unmaintained with multiple unfixed security vulnerabilities
EXPIRATION_DATE=2025-09-12

# See note in textproc/libxml2 for why this port uses autotools
USES=		cpe gmake gnome libtool localbase:ldflags pathfix pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--without-python
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	LIBVERSION=${PORTVERSION}

OPTIONS_DEFINE=	CRYPTO PLUGINS STATIC
OPTIONS_DEFAULT=	CRYPTO PLUGINS STATIC
OPTIONS_SUB=		yes

CRYPTO_DESC=	Enable crypto support
PLUGINS_DESC=	Enable dynamically-loaded plugins support

CRYPTO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
CRYPTO_CONFIGURE_WITH=	crypto

PLUGINS_CONFIGURE_WITH=	plugins

STATIC_CONFIGURE_ENABLE=	static

.include <bsd.port.mk>
