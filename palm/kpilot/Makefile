# New ports collection makefile for:   kpilot
# Version required:    3.0.2
# Date created:        09 April 1998
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.20 1998/11/06 21:17:17 nectar Exp $
#

DISTNAME=	kpilot-3.0.2
CATEGORIES=	palm comms kde
MASTER_SITES=	http://www.slac.com/pilone/kpilot_home/download/

MAINTAINER=	dima@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs \
		jscript.0:${PORTSDIR}/x11/kdelibs \
		khtmlw.1:${PORTSDIR}/x11/kdelibs \
		kfm.1:${PORTSDIR}/x11/kdelibs \
		mediatool.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
KDEDIR?=	$(PREFIX)
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-extra-includes=$(PREFIX)/include/giflib"
USE_GMAKE=	yes

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555" \
		KDEDIR="${KDEDIR}"

MAKE_ENV=	KDEDIR="${KDEDIR}"

pre-configure:
		${CP} ${FILESDIR}/libtool.${PORTOBJFORMAT} ${WRKSRC}/kpilot/libpilot/libtool
		${CP} ${FILESDIR}/ltmain.sh ${WRKSRC}/kpilot/libpilot/ltmain.sh

.include <bsd.port.mk>
