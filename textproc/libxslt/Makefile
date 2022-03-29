# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	libxslt
DISTVERSION=	1.1.35
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${DISTVERSION:R}/
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML stylesheet transformation library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicudata.so:devel/icu
USES=		cpe gmake gnome libtool localbase:ldflags pathfix pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
# many ports use xsltproc as a BUILD_DEPENDS, using cmake can cause dependency loops
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--without-python
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	CRYPTO MEM_DEBUG
OPTIONS_DEFAULT=	CRYPTO

CRYPTO_DESC=	Enable crypto support
MEM_DEBUG_DESC=	Enable memory debugging

CRYPTO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
CRYPTO_CONFIGURE_WITH=	crypto

MEM_DEBUG_CONFIGURE_WITH=	mem-debug

post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
