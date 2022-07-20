PORTNAME=	bulk_extractor
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	sysutils

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

USES=		autoreconf compiler:c++17-lang gnome iconv:wchar_t localbase \
		sqlite ssl
USE_GITHUB=	yes
USE_GNOME=	libxml2

GH_ACCOUNT=	simsong
GH_TUPLE=	simsong:be20_api:${GH_TAG_BE20_API}:be20_api \
		dfxml-working-group:dfxml_cpp:${GH_TAG_DFXML_CPP}:dfxml_cpp \
		dfxml-working-group:dfxml_schema:${GH_TAG_DFXML_SCHEMA}:dfxml_schema
GH_TAGNAME=	v${PORTVERSION}
GH_TAG_BE20_API=	f63dcd5
GH_TAG_DFXML_CPP=	09030bc
GH_TAG_DFXML_SCHEMA=	f2a702e

GNU_CONFIGURE=	yes
CXXFLAGS_powerpc=	-DBIG_ENDIAN
CXXFLAGS_powerpcspe=	-DBIG_ENDIAN
CONFIGURE_ARGS=	--enable-exiv2=true

PLIST_FILES=	bin/bulk_extractor bin/test_be man/man1/bulk_extractor.1.gz

post-extract:
	${CP} -R ${WRKSRC_be20_api}/* ${WRKSRC}/src/be20_api/
	${CP} -R ${WRKSRC_dfxml_cpp}/* ${WRKSRC}/src/be20_api/dfxml_cpp/
	${CP} -R ${WRKSRC_dfxml_schema}/* ${WRKSRC}/dfxml_schema/

.include <bsd.port.mk>
