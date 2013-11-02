# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bulk_extractor
PORTVERSION=	1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.digitalcorpora.org/downloads/bulk_extractor/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program that scans a disk image and extracts useful information

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libafflib.so:${PORTSDIR}/sysutils/afflib \
		libewf.so:${PORTSDIR}/devel/libewf \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libexpat.so:${PORTSDIR}/textproc/expat2

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

.if ${ARCH} == i386 && ! ${CFLAGS:M-march=*}
# Needed for __sync_add_and_fetch_8
CFLAGS+=	-march=i586
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV=	LEX=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.mk>
