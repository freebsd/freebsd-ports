# New ports collection makefile for:   kdeutils
# Version required:    Beta2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.12 1998/05/04 20:23:03 jseger Exp $
#

DISTNAME=	kdeutils-beta4-1
PKGNAME=	kdeutils-4.1b
CATEGORIES=	misc kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/Beta4/distribution/tgz/source
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	se@freebsd.org

BROKEN=		upgrade to 1.0 will be committed within the next few days

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar -xf -

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

WRKSRC=		${WRKDIR}/kdeutils

.include <bsd.port.mk>
