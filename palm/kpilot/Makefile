# New ports collection makefile for:   kpilot
# Version required:    2.0
# Date created:        09 April 1998
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.4 1998/05/04 20:23:08 jseger Exp $
#

DISTNAME=	kpilot-3.0
CATEGORIES=	x11 kde
MASTER_SITES=	http://www.slac.com/pilone/kpilot_home/download/

MAINTAINER=	dima@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.[6-9]:${PORTSDIR}/x11/kdelibs

KDEDIR?=	$(PREFIX)
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-extra-includes=$(PREFIX)/include/giflib"
USE_GMAKE=	yes

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555" \
		KDEDIR="${KDEDIR}"

MAKE_ENV=	KDEDIR="${KDEDIR}"

pre-configure:
		${CP} ${FILESDIR}/libtool ${FILESDIR}/ltmain.sh $(WRKSRC)/kpilot/libpilot

.include <bsd.port.mk>
