# New ports collection makefile for:    fusefs-ifuse
# Date created:                         09 October 2011
# Whom:                                 Gabor Zahemszky
#
# $FreeBSD$
#

PORTNAME=	ifuse
PORTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	Gabor@Zahemszky.HU
COMMENT=	Mount iPod Touch / iPhone directories over USB

# LICENSE=	LGPL21
# LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	imobiledevice.1:${PORTSDIR}/comms/libimobiledevice

RUN_DEPENDS=	usbmuxd:${PORTSDIR}/comms/usbmuxd

SUB_FILES=	pkg-message
USE_BZIP2=	yes
USE_FUSE=	yes
USE_GNOME=	glib20 pkgconfig

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS}

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
