# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bulk_extractor
PORTVERSION=	1.5.5
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://digitalcorpora.org/downloads/bulk_extractor/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program that scans a disk image and extracts useful information

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libafflib.so:sysutils/afflib \
		libboost_system.so:devel/boost-libs \
		libewf.so:devel/libewf \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2

USES=		autoreconf compiler:c++11-lang gnome iconv:wchar_t localbase \
		sqlite ssl
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes
CXXFLAGS_powerpc=	-DBIG_ENDIAN
CXXFLAGS_powerpcspe=	-DBIG_ENDIAN
CXXFLAGS_powerpc64=	-DBIG_ENDIAN
CONFIGURE_ARGS=	--enable-exiv2=true

PLIST_FILES=	bin/bulk_extractor bin/plugin_test man/man1/bulk_extractor.1.gz

OPTIONS_DEFINE=	BEVIEWER
BEVIEWER_DESC=	Build BEViewer (requires Java)
OPTIONS_DEFAULT=BEVIEWER

BEVIEWER_CONFIGURE_OFF=	--disable-BEViewer
BEVIEWER_USE=	JAVA=yes
BEVIEWER_PLIST_FILES=	bin/BEViewer bin/BEViewer.jar

.include <bsd.port.mk>
