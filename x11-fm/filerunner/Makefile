# New ports collection makefile for:	filerunner
# Date created:		3 August 1996
# Whom:			lukin
#
# $FreeBSD$
#

PORTNAME=	filerunner
PORTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	x11-fm tk
MASTER_SITES=	${MASTER_SITE_NETBSD} \
		http://www.cd.chalmers.se/~hch/
DISTNAME=	FileRunner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filemanager with FTP capabilities. Uses Tcl/Tk

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

MAKEFILE=	Makefile.freebsd_gcc

pre-build:
#	@ ${RM} ${WRKSRC}/ext.so
	@ ${CP} ${WRKSRC}/Makefiles/Makefile.freebsd_gcc ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
	@${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@${INSTALL_SCRIPT} ${WRKSRC}/frcolor ${PREFIX}/lib/FileRunner
	@${INSTALL_SCRIPT} ${WRKSRC}/frftp ${PREFIX}/lib/FileRunner
	@${LN} -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
.for file in COPYING FAQ HISTORY KnownBugs.txt QuickStart.txt README Tips.txt \
	Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog.tcl ext.so font.tcl \
	ftp.tcl http.tcl tclIndex
		@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
.for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit \
	right.bit smaller.bit toggle.bit tree.bit up.bit update.bit xterm.bit
		@${INSTALL_DATA} ${WRKSRC}/bitmaps/${map} ${PREFIX}/lib/FileRunner/bitmaps
.endfor

.include <bsd.port.mk>
