# New ports collection makefile for:	x-files
# Version required:     1.43
# Date created:		14 April 1998
# Whom:			Donald J. Maddox <dmaddox@conterra.com>
#
# $FreeBSD$
#

DISTNAME=       X-Files-1.43
PKGNAME=	x-files-1.43
CATEGORIES=	x11-fm tk80
MASTER_SITES=   http://www.hut.fi/~mkivinie/X-Files/data/

MAINTAINER=     dmaddox@conterra.com

BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/X-Files
NO_BUILD=	yes
USE_X_PREFIX=	yes

pre-install:
	@tclsh8.0 ${SCRIPTDIR}/mktclIndex ${WRKSRC}
	@${SED} s#@X11BASE@#${X11BASE}# <${WRKSRC}/X-Files.tcl >${WRKSRC}/tmpfile
	@${MV} ${WRKSRC}/tmpfile ${WRKSRC}/X-Files.tcl

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
