# Created by: Matthew N. Dodd <mdodd@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spamprobe
PORTVERSION=	1.4d
PORTREVISION=	16
CATEGORIES=		mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spam detector using Bayesian analysis of word counts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-default-8bit
USE_GCC=	any

PLIST_FILES=	bin/spamprobe man/man1/spamprobe.1.gz

OPTIONS_DEFINE=	GIF JPEG PNG
OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	PBL BDB
OPTIONS_DEFAULT=PBL GIF JPEG PNG
PBL_DESC=		PBL database support (author's recommended data store)

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# PBL support
PBL_BUILD_DEPENDS=	${LOCALBASE}/lib/libpbl.a:databases/libpbl
PBL_RUN_DEPENDS+=	${PBL_BUILD_DEPENDS}
PBL_CONFIGURE_WITH=	pbl
PBL_LDFLAGS=	-lpbl

# BerkleyDB support
BDB_CONFIGURE_ENABLE=	cdb
BDB_CONFIGURE_WITH=	db
BDB_CPPFLAGS=	-DUSE_DB=1

# giflib support
GIF_CONFIGURE_WITH=	gif
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib

# PNG support
PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

# JPEG support
JPEG_CONFIGURE_WITH=jpeg
JPEG_USES=		jpeg

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USES+=		bdb
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-l${BDB_LIB_NAME}
.endif

.include <bsd.port.mk>
