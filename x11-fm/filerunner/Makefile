# New ports collection makefile for:	filerunner
# Version required:	2.4
# Date created:		3 August 1996
# Whom:			lukin
#
# $Id: Makefile,v 1.9 1997/10/14 06:42:34 tg Exp $
#

DISTNAME=	FileRunner-2.4
PKGNAME=	filerunner-2.4
CATEGORIES=	x11 tk80
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop
EXTRACT_SUFX=	.tgz

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/FileRunner_2.4
MAKEFILE=	Makefile.freebsd
MAKE_ENV+=	X11BASE=${X11BASE}

pre-build:
	@ ${RM} ${WRKSRC}/ext.o
	@ ${RM} ${WRKSRC}/ext.so
	@ ${CP} ${WRKSRC}/Makefiles/Makefile.freebsd ${WRKSRC}

do-install:
	@ ${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
	@ ${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@ ln -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for file in FAQ HISTORY QuickStart.txt Tips Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl frcolor frftp ftp.tcl http.tcl palette.tcl tclIndex
		@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		@ ${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include <bsd.port.mk>
