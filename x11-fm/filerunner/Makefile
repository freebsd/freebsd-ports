# New ports collection makefile for:	filerunner
# Date created:		3 August 1996
# Whom:			lukin
#
# $FreeBSD$
#

PORTNAME=	filerunner
PORTVERSION=	2.5
CATEGORIES=	x11-fm tk82
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop
DISTNAME=	FileRunner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filemanager with FTP capabilities. Uses Tcl/Tk

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

MAKEFILE=	Makefile.freebsd_gcc
MAKE_ENV+=	X11BASE=${X11BASE}

pre-build:
#	@ ${RM} ${WRKSRC}/ext.so
	@ ${CP} ${WRKSRC}/Makefiles/Makefile.freebsd_gcc ${WRKSRC}

do-install:
	@ ${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
	@ ${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@ ${INSTALL_SCRIPT} ${WRKSRC}/frcolor ${PREFIX}/lib/FileRunner
	@ ${INSTALL_SCRIPT} ${WRKSRC}/frftp ${PREFIX}/lib/FileRunner
	@ ${LN} -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for file in FAQ HISTORY QuickStart.txt Tips.txt Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl ftp.tcl http.tcl tclIndex
		@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		@ ${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include <bsd.port.mk>
