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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual chat program written in Tcl/Tk

RUN_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/OpenVerse

STRIP=	# Nothing to Strip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${LOCALBASE}/bin/wish8.2|g' \
	-e 's|/usr/lib/OpenVerse|${PREFIX}/lib/OpenVerse|g' \
		${WRKSRC}/OpenVerse.tcl

do-install:
.for DIR in anims icons images language lib panels plugins/Query rooms
	${MKDIR} ${PREFIX}/lib/OpenVerse/${DIR}
	${INSTALL_DATA} ${WRKSRC}/${DIR}/* ${PREFIX}/lib/OpenVerse/${DIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/OpenVerse.tcl ${WRKSRC}/server.tcl \
		${PREFIX}/lib/OpenVerse/
	${INSTALL_DATA} ${WRKSRC}/server.cfg ${WRKSRC}/passageways.txt \
		${PREFIX}/lib/OpenVerse/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/doc/OpenVerse/help
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/OpenVerse/README
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/OpenVerse/OpenVerse.tcl ${PREFIX}/bin/OpenVerse

.include <bsd.port.mk>
