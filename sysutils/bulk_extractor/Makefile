# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>

PORTNAME=	bulk_extractor
DISTVERSION=	2.0.0-beta3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/simsong/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program that scans a disk image and extracts useful information

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libafflib.so:sysutils/afflib \
		libboost_system.so:devel/boost-libs \
		libewf.so:devel/libewf \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		compiler:c++17-lang gnome iconv:wchar_t localbase \
		sqlite ssl
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes
CXXFLAGS_powerpc=	-DBIG_ENDIAN
CXXFLAGS_powerpcspe=	-DBIG_ENDIAN
CXXFLAGS_powerpc64=	-DBIG_ENDIAN
CONFIGURE_ARGS=	--enable-exiv2=true

PLIST_FILES=	bin/bulk_extractor bin/test_be man/man1/bulk_extractor.1.gz

.include <bsd.port.mk>
