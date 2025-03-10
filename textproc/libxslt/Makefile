PORTNAME=	libxslt
DISTVERSION=	1.1.42
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${DISTVERSION:R}/
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/libxslt/-/commit/
PATCHFILES=	bf59c338121b8b45d66ba6ecea69ad498015c396.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML stylesheet transformation library
WWW=		https://gitlab.gnome.org/GNOME/libxslt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

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

OPTIONS_DEFINE=	CRYPTO STATIC
OPTIONS_DEFAULT=	CRYPTO STATIC
OPTIONS_SUB=		yes

CRYPTO_DESC=	Enable crypto support

CRYPTO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
CRYPTO_CONFIGURE_WITH=	crypto

STATIC_CONFIGURE_ENABLE=	static

.include <bsd.port.mk>
