PORTNAME=		spamprobe
PORTVERSION=	1.4d
PORTREVISION=	21
CATEGORIES=		mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spam detector using Bayesian analysis of word counts
WWW=		https://spamprobe.sourceforge.net/

USES=	localbase:ldflags
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-default-8bit

PLIST_FILES=	bin/spamprobe share/man/man1/spamprobe.1.gz

OPTIONS_DEFINE=	GIF JPEG PNG
OPTIONS_DEFAULT=PBL GIF JPEG PNG
OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	PBL BDB

PBL_DESC=		PBL database support (author's recommended data store)

# BerkleyDB support
BDB_USES=		bdb
BDB_CONFIGURE_ENABLE=	cdb
BDB_CONFIGURE_WITH=	db
BDB_CPPFLAGS=	-DUSE_DB=1 -I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=	-l${BDB_LIB_NAME}

# giflib support
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=	gif

# JPEG support
JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=jpeg

# PBL support
PBL_BUILD_DEPENDS=	${LOCALBASE}/lib/libpbl.a:databases/libpbl
PBL_RUN_DEPENDS+=	${PBL_BUILD_DEPENDS}
PBL_CONFIGURE_WITH=	pbl
PBL_LDFLAGS=	-lpbl

# PNG support
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

.include <bsd.port.mk>
