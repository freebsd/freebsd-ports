# New ports collection makefile for:   kdenetwork
# Version required:    Beta3
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.8 1998/03/06 19:52:18 se Exp $
#

DISTNAME=	kdenetwork-Beta3-1
PKGNAME=	kdenetwork-3.1b
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/Beta3/distribution/tgz/source 
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt \
		${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.[67]\\.:${PORTSDIR}/graphics/jpeg \
		uu\\.1\\.:${PORTSDIR}/converters/uulib \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.[6-9]:${PORTSDIR}/x11/kdelibs \
		mimelib\\.1\\.[0-9]:${PORTSDIR}/converters/kdesupport

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

WRKSRC=		${WRKDIR}/kdenetwork

pre-configure:
		${LN} -sf $(PREFIX)/include/uu.h $(WRKSRC)/krn/uudeview.h

.include <bsd.port.mk>
