# New ports collection makefile for:	filerunner
# Version required:	2.1
# Date created:		3 August 1996
# Whom:			lukin
#
# $Id: Makefile,v 1.2 1996/11/05 17:53:16 jfitz Exp $
#

DISTNAME=	FileRunner_2.0
PKGNAME=	filerunner-2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils/managers
EXTRACT_SUFX=	.tgz

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

MAKEFILE=	Makefile.freebsd
MAKE_ENV+=	X11BASE=${X11BASE}

pre-build:
	@ ${RM} ${WRKSRC}/ext.so

do-install:
	@ ${MKDIR} -p ${PREFIX}/lib/FileRunner
	@ ${INSTALL_SCRIPT} ${WRKSRC}/fr ${PREFIX}/lib/FileRunner
	@ ln -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin
	@ for file in cmd.tcl config.tcl cross.bit ext.so font.tcl frcolor frftp frterm.bit ftp.tcl guide larger.bit left.bit max.bit pgdown.bit pgup.bit quickstart right.bit smaller.bit tclIndex up.bit update.bit xterm.bit; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/FileRunner; \
	done

.include <bsd.port.mk>
