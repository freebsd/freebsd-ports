# New ports collection makefile for:   kdenetwork
# Version required:    Beta4
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.26 1999/02/03 11:11:55 asami Exp $
#

DISTNAME=	kdenetwork-1.1pre2
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1pre2/distribution/tar/generic/source

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		uu.1:${PORTSDIR}/converters/uulib \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		QwSpriteField.6:${PORTSDIR}/converters/kdesupport11 \
		js.2:${PORTSDIR}/converters/kdesupport11 \
		mimelib.1:${PORTSDIR}/converters/kdesupport11 \
		rdb.55:${PORTSDIR}/converters/kdesupport11

USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"
CFLAGS+=	"-I${PREFIX}/include"

pre-configure:
		${LN} -sf $(PREFIX)/include/uu.h $(WRKSRC)/krn/uudeview.h

post-install:
		${LN} -sf kppp.html ${PREFIX}/share/doc/HTML/en/kppp/index.html

.include <bsd.port.mk>
