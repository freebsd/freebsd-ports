PORTNAME=	bulk_extractor
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program that scans a disk image and extracts useful information
WWW=		https://github.com/simsong/bulk_extractor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libewf.so:devel/libewf \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libre2.so:devel/re2

USES=		autoreconf compiler:c++17-lang gnome iconv:wchar_t \
		libtool pkgconfig python:build sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	simsong

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-exiv2=true

TEST_TARGET=	check

PLIST_FILES=	bin/bulk_extractor share/man/man1/bulk_extractor.1.gz

pre-configure:
	(cd ${WRKSRC} && ${PYTHON_CMD} etc/makefile_builder.py)

.include <bsd.port.mk>
