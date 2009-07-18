# New ports collection makefile for:    spamprobe
# Whom:                                 Matthew N. Dodd <mdodd@FreeBSD.org>
# Date created:                         05 September 2002
#
# $FreeBSD$
#
# Available options for this port:
# WITHOUT_PBL   - disable support for PBL database storage
# WITHOUT_BDB   - disable support for BDB database storage
# WITHOUT_UNGIF - disable analysis of image attachments using libungif
# WITHOUT_PNG   - disable analysis of image attachments using libpng
# WITHOUT_JPEG  - disable analysis of image attachments using libjpeg
#

PORTNAME=	spamprobe
PORTVERSION=	1.4d
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Spam detector using Bayesian analysis of word counts

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-default-8bit

MAN1=		spamprobe.1
PLIST_FILES=	bin/spamprobe

# PBL support
.if !defined(WITHOUT_PBL)
BUILD_DEPENDS+=	${LOCALBASE}/include/pbl.h:${PORTSDIR}/databases/libpbl
CONFIGURE_ARGS+=	--with-pbl=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpbl
.endif

# BerkleyDB support
.if !defined(WITHOUT_BDB)
USE_BDB=	3+
INVALID_BDB_VER=2
CONFIGURE_ARGS+=	--enable-cdb
CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -DUSE_DB=1
LDFLAGS+=	-L${LOCALBASE}/lib -l${BDB_LIB_NAME}
.endif

# libungif support
.if defined(WITHOUT_UNGIF)
CONFIGURE_ARGS+=	--without-gif
.else
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

# PNG support
.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--without-png
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

# JPEG support
.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--without-jpeg
.else
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.include <bsd.port.mk>
