# New ports collection makefile for:	x-files
# Version required:     1.43
# Date created:		14 April 1998
# Whom:			Donald J. Maddox <dmaddox@conterra.com>
#
# $Id: Makefile,v 1.6 1998/12/02 20:08:57 billf Exp $
#

DISTNAME=       X-Files-1.43
PKGNAME=	x-files-1.43
CATEGORIES=	x11-fm tk80
MASTER_SITES=   http://java.inf.tu-dresden.de/X-Files/data/

MAINTAINER=     dmaddox@scsn.net

BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

.if !defined(DISPLAY)
BROKEN=		requires DISPLAY to install
.endif

WRKSRC=		${WRKDIR}/X-Files
NO_BUILD=	yes
USE_X_PREFIX=	yes

pre-install:
	@wish8.0 ${SCRIPTDIR}/mktclIndex ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/X-Files
	@${INSTALL_SCRIPT} ${WRKSRC}/X-Files.tcl ${PREFIX}/bin/X-Files
.for file in be.tcl ee.tcl re.tcl vfs.tcl xf_sel.tcl xfiles.buttons xfiles.extensions tclIndex \
xfiles.faq xfiles.headers xfiles.main_pophelp xfiles.manual xfiles.user_pophelp \
xfilesrc xflogo.gif
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/X11/X-Files
.endfor
	@${INSTALL_DATA} ${WRKSRC}/X-Files.xpm ${X11BASE}/include/X11/pixmaps
	@${INSTALL_MAN} ${WRKSRC}/X-Files.1x ${X11BASE}/man/man1

.include <bsd.port.mk>
