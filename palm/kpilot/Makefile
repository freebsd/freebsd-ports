# New ports collection makefile for:   kpilot
# Version required:    3.0.2
# Date created:        09 April 1998
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.7 1998/08/07 23:56:11 asami Exp $
#

DISTNAME=	kpilot-3.0.2
CATEGORIES=	x11 kde
MASTER_SITES=	http://www.slac.com/pilone/kpilot_home/download/

MAINTAINER=	dima@freebsd.org

LIB_DEPENDS=	gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.[6-9]:${PORTSDIR}/x11/kdelibs

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
		${CP} ${FILESDIR}/libtool ${FILESDIR}/ltmain.sh $(WRKSRC)/kpilot/libpilot

.include <bsd.port.mk>
