# New ports collection makefile for:	filerunner
# Version required:	2.5
# Date created:		3 August 1996
# Whom:			lukin
#
# $Id: Makefile,v 1.15 1998/08/07 22:33:11 asami Exp $
#

DISTNAME=	FileRunner-2.5
PKGNAME=	filerunner-2.5
CATEGORIES=	x11-fm tk81
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	tk81\\.1:${PORTSDIR}/x11-toolkits/tk81

MAKEFILE=	Makefile.freebsd_gcc
MAKE_ENV+=	X11BASE=${X11BASE}

pre-build:
#	@ ${RM} ${WRKSRC}/ext.so
	@ ${CP} ${WRKSRC}/Makefiles/Makefile.freebsd_gcc ${WRKSRC}

do-install:
	@ ${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
	@ ${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@ ln -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for file in FAQ HISTORY QuickStart.txt Tips.txt Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl frcolor frftp ftp.tcl http.tcl tclIndex
		@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		@ ${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include <bsd.port.mk>
