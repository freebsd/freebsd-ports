# New ports collection makefile for:   kdeutils
# Version required:    Beta2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	kdeutils-1.1.2
CATEGORIES=	misc kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"
USE_GMAKE=	yes

.include <bsd.port.mk>
