# Created by: Gabor Zahemszky
# $FreeBSD$

PORTNAME=	ifuse
PORTVERSION=	1.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	Gabor@Zahemszky.HU
COMMENT=	FUSE-based filesystem for mounting iOS devices over USB

LICENSE=	LGPL21

LIB_DEPENDS=	plist:${PORTSDIR}/devel/libplist \
		imobiledevice:${PORTSDIR}/comms/libimobiledevice
RUN_DEPENDS=	usbmuxd:${PORTSDIR}/comms/usbmuxd

USE_GNOME=	glib20
USES=		fuse pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

MAN1=		ifuse.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
