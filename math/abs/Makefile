# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	abs
PORTVERSION=	0908
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	gmarco@gufi.org
COMMENT=	A free spreadsheet with graphical user interface

PLIST_FILES=	bin/abs
USE_XORG=	x11 xpm xaw
WRKSRC=		${WRKDIR}/abs-src-0.908

NO_STAGE=	yes
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
