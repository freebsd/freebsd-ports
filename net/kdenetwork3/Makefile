# New ports collection makefile for:   kdenetwork
# Version required:    Beta4
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	kdenetwork-1.1.2
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		uu.1:${PORTSDIR}/converters/uulib \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		QwSpriteField.6:${PORTSDIR}/converters/kdesupport11 \
		js.2:${PORTSDIR}/converters/kdesupport11 \
		mimelib.1:${PORTSDIR}/converters/kdesupport11 \
		rdb.55:${PORTSDIR}/converters/kdesupport11

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"
USE_GMAKE=	yes
CFLAGS+=	"-I${PREFIX}/include"

.include <bsd.port.pre.mk>

# ksirc needs egcs
.if ${OSVERSION} < 400004
PLIST=	${PKGDIR}/PLIST.noksirc
.endif

.include <bsd.port.post.mk>
