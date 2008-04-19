# New ports collection makefile for:	x-files
# Date created:		14 April 1998
# Whom:			Donald J. Maddox <dmaddox099@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	x-files
PORTVERSION=	2.00b1
PORTREVISION=	3
CATEGORIES=	x11-fm tk
MASTER_SITES=	http://users.tkk.fi/~mkivinie/X-Files/data/
DISTNAME=	X-Files-${PORTVERSION}

MAINTAINER=	dmaddox099@yahoo.com
COMMENT=	A nice Tk-based filemanager

BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/X-Files
NO_BUILD=	yes
MAN1=		X-Files.1x

pre-install:
	@tclsh8.3 ${SCRIPTDIR}/mktclIndex ${WRKSRC}
	@${RM} -f ${WRKSRC}/xfinstall.tcl
	@${SED} s#@PREFIX@#${PREFIX}# <${WRKSRC}/X-Files.tcl >${WRKSRC}/tmpfile
	@${MV} ${WRKSRC}/tmpfile ${WRKSRC}/X-Files.tcl

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/X-Files
.for file in *.tcl xfiles* xflogo.gif Registration.form
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/X11/X-Files
.endfor
	@${CHMOD} 0555 ${PREFIX}/lib/X11/X-Files/X-Files.tcl
	@${LN} -s ${PREFIX}/lib/X11/X-Files/X-Files.tcl ${PREFIX}/bin/X-Files
	@${MKDIR} ${PREFIX}/include/X11/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/X-Files.xpm ${PREFIX}/include/X11/pixmaps
	@${INSTALL_MAN} ${WRKSRC}/X-Files.1x ${PREFIX}/man/man1

.include <bsd.port.mk>
