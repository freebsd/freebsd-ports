# Created by: jkh
# $FreeBSD$

PORTNAME=	ghostview
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://ftp.gnu.org/old-gnu/ghostview/ \
		http://ftp.sunet.se/pub/text-processing/postscript/interpreters/ghostscript/gnu/ghostview/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 front-end for ghostscript, the GNU postscript previewer

LICENSE=	GPLv2 # (or later)

USES=		imake
USE_XORG=	xbitmaps xaw
USE_GHOSTSCRIPT_RUN=	yes
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-Wno-error=return-type

MAN1=		ghostview.1
PLIST_FILES=	bin/ghostview \
		lib/X11/app-defaults/Ghostview

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
