# New ports collection makefile for:   kdeutils
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1997/11/02 00:05:02 se Exp $
#

DISTNAME=	kdeutils-Beta1-2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta1/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta1/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta1/distribution/tgz/source/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	${X11BASE}/bin/moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.[67]\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.1[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.1[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.[1-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.1[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.[1-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.[6-9]:${PORTSDIR}/x11/kdelibs

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=$(X11BASE)/include -I$(PREFIX)/include -I$(PREFIX)/include/giflib" \
		"--x-lib=$(X11BASE)/lib -L$(PREFIX)/lib" \
		"--prefix=$(PREFIX)" \
		"--datadir=$(PREFIX)/share/kde"

WRKSRC=		${WRKDIR}/kdeutils

.include <bsd.port.mk>
