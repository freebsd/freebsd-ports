# New ports collection makefile for:   kdenetwork
# Version required:    Beta4
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.15 1998/07/19 17:47:33 se Exp $
#

DISTNAME=	kdenetwork-1.0
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.0/distribution/tar/generic/source

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt140 \
		${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	qt\\.1\\.\\\(33\\\|40\\\):${PORTSDIR}/x11/qt140 \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		uu\\.1\\.:${PORTSDIR}/converters/uulib \
		kdecore\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		mimelib\\.1\\.[0-9]:${PORTSDIR}/converters/kdesupport

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

pre-configure:
		${LN} -sf $(PREFIX)/include/uu.h $(WRKSRC)/krn/uudeview.h

.include <bsd.port.mk>
