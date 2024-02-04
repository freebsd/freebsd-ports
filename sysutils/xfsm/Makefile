PORTNAME=	xfsm
PORTVERSION=	1.99
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE/system/status/xstatus

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X File System Monitor

USES=		imake tar:tgz xorg
USE_XORG=	xbitmaps x11 xext
MAKE_ARGS=	CC="${CC}" CCOPTIONS="-DFreeBSD"
PLIST_FILES=	bin/xfsm share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
