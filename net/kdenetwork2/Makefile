# New ports collection makefile for:   kdenetwork
# Version required:    Beta4
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.22 1998/10/01 18:35:37 brian Exp $
#

DISTNAME=	kdenetwork
PKGNAME=	kdenetwork-1.1a1
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1pre1/distribution/tar/generic/source
EXTRACT_SUFX=	-1.1-alpha1.src.tar.bz2

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		uu.1:${PORTSDIR}/converters/uulib \
		kdecore.2:${PORTSDIR}/x11/kdelibs \
		QwSpriteField.6:${PORTSDIR}/converters/kdesupport \
		js.2:${PORTSDIR}/converters/kdesupport \
		mimelib.1:${PORTSDIR}/converters/kdesupport \
		rdb.55:${PORTSDIR}/converters/kdesupport
EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar xf -

USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

pre-configure:
		${LN} -sf $(PREFIX)/include/uu.h $(WRKSRC)/krn/uudeview.h

.include <bsd.port.mk>
