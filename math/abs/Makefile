# New ports collection makefile for:   abs
# Date created:        20 January 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	abs
PORTVERSION=	0908
CATEGORIES=	math
MASTER_SITES=	http://www.giovannelli.it/~gmarco/files/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	A free spreadsheet with graphical user interface

PLIST_FILES=	bin/abs
USE_XLIB=	yes
USE_XPM=	yes
WRKSRC=		${WRKDIR}/abs-src-0.908

post-patch:
	@${REINPLACE_CMD} -e 's/trcasestr/strcasestr_/g' ${WRKSRC}/Database/cell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

post-install:
	@${ECHO_MSG} "For the changes from previous version"
	@${ECHO_MSG} "you can read the NEWS file in ${WRKSRC}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are also some examples (not installed) in :"
	@${ECHO_MSG} "${WRKSRC}/Examples"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
