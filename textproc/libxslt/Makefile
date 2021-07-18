# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	libxslt
DISTVERSION=	1.1.34
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	http://xmlsoft.org/sources/ \
		https://mirror.umd.edu/xbmc/build-deps/sources/
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML stylesheet transformation library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake gnome localbase libtool pathfix pkgconfig
CPE_VENDOR=	xmlsoft
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--without-python

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	CRYPTO MEM_DEBUG
OPTIONS_DEFAULT=CRYPTO

CRYPTO_DESC=	Enable crypto support
MEM_DEBUG_DESC=	Enable memory debugging

CRYPTO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
CRYPTO_CONFIGURE_WITH=	crypto
MEM_DEBUG_CONFIGURE_ON=	--with-mem-debug

post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
