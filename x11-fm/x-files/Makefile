# New ports collection makefile for:	x-files
# Date created:		14 April 1998
# Whom:			Donald J. Maddox <dmaddox099@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	x-files
PORTVERSION=	2.00b1
CATEGORIES=	x11-fm tk83
MASTER_SITES=	http://www.hut.fi/~mkivinie/X-Files/data/
DISTNAME=	X-Files-${PORTVERSION}

MAINTAINER=	dmaddox099@yahoo.com
COMMENT=	A nice Tk-based filemanager

BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/X-Files
NO_BUILD=	yes
USE_X_PREFIX=	yes
MAN1=		X-Files.1x

pre-install:
	@tclsh8.3 ${SCRIPTDIR}/mktclIndex ${WRKSRC}
	@${RM} -f ${WRKSRC}/xfinstall.tcl
	@${SED} s#@X11BASE@#${X11BASE}# <${WRKSRC}/X-Files.tcl >${WRKSRC}/tmpfile
	@${MV} ${WRKSRC}/tmpfile ${WRKSRC}/X-Files.tcl

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/X-Files
.for file in *.tcl xfiles* xflogo.gif Registration.form
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/X11/X-Files
.endfor
	@${CHMOD} 0555 ${PREFIX}/lib/X11/X-Files/X-Files.tcl
	@${LN} -s ${PREFIX}/lib/X11/X-Files/X-Files.tcl ${PREFIX}/bin/X-Files
	@${MKDIR} ${X11BASE}/include/X11/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/X-Files.xpm ${X11BASE}/include/X11/pixmaps
	@${INSTALL_MAN} ${WRKSRC}/X-Files.1x ${X11BASE}/man/man1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-4
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
