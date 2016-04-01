# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bulk_extractor
PORTVERSION=	1.5.5
CATEGORIES=	sysutils
MASTER_SITES=	http://digitalcorpora.org/downloads/bulk_extractor/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program that scans a disk image and extracts useful information

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		sqlite
LIB_DEPENDS=	libafflib.so:sysutils/afflib \
		libewf.so:devel/libewf \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-exiv2=true
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/bulk_extractor bin/plugin_test man/man1/bulk_extractor.1.gz

OPTIONS_DEFINE=	BEVIEWER
BEVIEWER_DESC=	Build BEViewer (requires Java)
OPTIONS_DEFAULT=BEVIEWER

BEVIEWER_CONFIGURE_OFF=	--disable-BEViewer
BEVIEWER_USE=	JAVA=yes
BEVIEWER_PLIST_FILES=	bin/BEViewer bin/BEViewer.jar

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
CONFIGURE_ENV=	LEX=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.mk>
