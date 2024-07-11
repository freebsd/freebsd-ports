PORTNAME=	ifuse
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/libimobiledevice/${PORTNAME}/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE-based filesystem for mounting iOS devices over USB
WWW=		https://www.libimobiledevice.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
		libimobiledevice-1.0.so:comms/libimobiledevice
RUN_DEPENDS=	usbmuxd:comms/usbmuxd

USES=		fuse localbase gnome pkgconfig tar:bzip2
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/${PORTNAME} share/man/man1/ifuse.1.gz

.include <bsd.port.mk>
