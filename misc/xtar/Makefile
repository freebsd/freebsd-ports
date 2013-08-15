# Created by: Andreas Kohout <shanee@rabbit.augusta.de>
# $FreeBSD$

PORTNAME=	xtar
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View and manipulate contents of a tar file

USES=		motif
USE_XORG=	ice sm x11 xext xp xt
MAKEFILE=	Makefile.noimake
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	XINC="-I${LOCALBASE}/include" XMLIB="${MOTIFLIB}" \
		APPDIR="${PREFIX}/lib/X11/app-defaults" \
		BINDIR="${PREFIX}/bin" LIBDIR="${PREFIX}/lib/X11/xtar" \
		MANDIR="${MAN1PREFIX}/man/man1" OPTIMISATION="${CFLAGS}" \
		ANSIFLAG=-ansi CC="${CC}" RANLIB=:

MAN1=		xtar.1
PLIST_FILES=	bin/xtar lib/X11/xtar/xtar.doc lib/X11/app-defaults/XTar
PLIST_DIRS=	lib/X11/xtar

post-patch:
	@${REINPLACE_CMD} -e 's/pipe\.c/& regexpr.c/' \
		${WRKSRC}/common/Makefile.noimake

.include <bsd.port.mk>
