# New ports collection makefile for:	filerunner
# Version required:	2.1
# Date created:		3 August 1996
# Whom:			lukin
#
# $Id: Makefile,v 1.4 1997/04/20 13:19:53 wosch Exp $
#

DISTNAME=	FileRunner_2.3
PKGNAME=	filerunner-2.3
CATEGORIES=	x11 tk41
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop
EXTRACT_SUFX=	.tgz

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	tk42\\.1:${PORTSDIR}/x11/tk42

MAKEFILE=	Makefile.freebsd
MAKE_ENV+=	X11BASE=${X11BASE}

pre-build:
	@ ${RM} ${WRKSRC}/ext.so
	@ cp ${WRKSRC}/Makefiles/Makefile.freebsd ${WRKSRC}

do-install:
	@ ${MKDIR} -p ${PREFIX}/lib/FileRunner
	@ ${MKDIR} -p ${PREFIX}/lib/FileRunner/bitmaps
	@ ${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@ ln -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
	@ for file in FAQ QuickStart.txt Users_Guide.txt chmod.tcl cmd.tcl config.tcl dialog_about.tcl ext.so font.tcl frcolor frftp ftp.tcl palette.tcl tclIndex; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/FileRunner; \
	done
	@ for map in cross.bit frterm.bit larger.bit left.bit max.bit pgdown.bit pgup.bit right.bit smaller.bit toggle.bit up.bit update.bit xterm.bit; do \
		${INSTALL_DATA} ${WRKSRC}/bitmaps/$$map ${PREFIX}/lib/FileRunner/bitmaps; \
	done

.include <bsd.port.mk>
