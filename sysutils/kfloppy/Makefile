# New ports collection makefile for:   kdeutils
# Version required:    Beta2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.26 1999/02/06 23:22:03 se Exp $
#

DISTNAME=	kdeutils-1.1
CATEGORIES=	misc kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1/distribution/tar/generic/source

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"
USE_GMAKE=	yes
CFLAGS+=	"-I${PREFIX}/include"

.include <bsd.port.mk>

#CONFIGURE_ARGS+="--with-install-root=/data/kde"
