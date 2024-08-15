PORTNAME=	bulk_extractor
PORTVERSION=	2.1.1
PORTREVISION=	1
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
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libre2.so:devel/re2

USES=		autoreconf compiler:c++17-lang gnome iconv:wchar_t \
		pkgconfig python:build sqlite ssl
USE_GITHUB=	yes

GH_ACCOUNT=	simsong
GH_TUPLE=	simsong:be20_api:${GH_TAG_BE20_API}:be20_api \
		dfxml-working-group:dfxml_cpp:${GH_TAG_DFXML_CPP}:dfxml_cpp \
		dfxml-working-group:dfxml_schema:${GH_TAG_DFXML_SCHEMA}:dfxml_schema \
		nemtrif:utfcpp:${GH_TAG_UTFCPP}:utfcpp
GH_TAG_BE20_API=	efa4d69
GH_TAG_DFXML_CPP=	1e92fe8
GH_TAG_DFXML_SCHEMA=	f2a702e
GH_TAG_UTFCPP=	6be08bb

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-exiv2=true

TEST_TARGET=	check

PLIST_FILES=	bin/bulk_extractor share/man/man1/bulk_extractor.1.gz

post-extract:
	${CP} -R ${WRKSRC_be20_api}/* ${WRKSRC}/src/be20_api/
	${CP} -R ${WRKSRC_dfxml_cpp}/* ${WRKSRC}/src/be20_api/dfxml_cpp/
	${CP} -R ${WRKSRC_utfcpp}/* ${WRKSRC}/src/be20_api/utfcpp/
	${CP} -R ${WRKSRC_dfxml_schema}/* ${WRKSRC}/dfxml_schema/

pre-configure:
	(cd ${WRKSRC} && ${PYTHON_CMD} etc/makefile_builder.py)

.include <bsd.port.mk>
