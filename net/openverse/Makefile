# Ports collection makefile for:	OpenVerse
# Date created:				24 Feb 2001
# Whom:					Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$

PORTNAME=	OpenVerse
PORTVERSION=	0.8.7
CATEGORIES=	net tk82
MASTER_SITES=	http://www.openverse.com/files/OpenVerse/
DISTNAME=	${PORTNAME}-0.8-7

MAINTAINER=	ahze@ahze.net
COMMENT=	A visual chat program written in Tcl/Tk

RUN_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/OpenVerse
USE_REINPLACE=	yes

STRIP=	# Nothing to strip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${PREFIX}/bin/wish8.2|g' \
	-e 's|/usr/lib/OpenVerse|${PREFIX}/lib/OpenVerse|g' \
		${WRKSRC}/OpenVerse.tcl

do-install:
.for DIR in anims icons images language lib panels plugins/Query rooms
	${MKDIR} ${PREFIX}/lib/OpenVerse/${DIR}
	${INSTALL_DATA} ${WRKSRC}/${DIR}/* ${PREFIX}/lib/OpenVerse/${DIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/OpenVerse.tcl ${WRKSRC}/server.cfg ${WRKSRC}/server.tcl \
		${WRKSRC}/passageways.txt ${PREFIX}/lib/OpenVerse/
	${MKDIR} ${PREFIX}/share/doc/OpenVerse/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/doc/OpenVerse/help
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/OpenVerse/README

post-install:
	@${ECHO} "Please read the documentation for OpenVerse located in"
	@${ECHO} "${PREFIX}/share/doc/OpenVerse/help and ${PREFIX}/share/doc/OpenVerse/README."
	${LN} -sf ${PREFIX}/lib/OpenVerse/OpenVerse.tcl ${PREFIX}/bin/OpenVerse

.include <bsd.port.mk>
