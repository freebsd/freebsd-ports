# Ports collection makefile for:	OpenVerse
# Date created:				24 Feb 2001
# Whom:					Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$

PORTNAME=	OpenVerse
PORTVERSION=	0.8.7
PORTREVISION=	3
CATEGORIES=	net tcl tk
MASTER_SITES=	http://www.openverse.com/files/OpenVerse/
DISTNAME=	${PORTNAME}-0.8-7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual chat program written in Tcl/Tk

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_TK_RUN=	yes
USE_TCL_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/OpenVerse

STRIP=	# Nothing to Strip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' \
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
