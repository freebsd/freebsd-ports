# New ports collection makefile for:	lensnns
# Date created:		9 jan 2007
# Whom:			Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	lensnns
PORTVERSION=	2.63
CATEGORIES=	math science
MASTER_SITES=	http://tedlab.mit.edu/~dr/Lens/Dist/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/
DISTNAME=	lens

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Light Efficient Neural Network Simulator

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_GMAKE=	yes

MAKE_ENV+=	HOSTTYPE="FreeBSD"

MAN1=		lensnns.1

SUB_FILES=	pkg-message lensnns.1
PKGMESSAGE=	${WRKDIR}/pkg-message
WEB_BROWSER?=	konqueror

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "========================================================"
	@${ECHO_CMD} "The default WEB browser for viewing the manual is KDE's"
	@${ECHO_CMD} "konqueror.  If you want to change this, type Ctrl+C now,"
	@${ECHO_CMD} "and run make again with -DWEB_BROWSER, e.g."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "	make -DWEB_BROWSER=firefox"
	@${ECHO_CMD} "========================================================"
	@${ECHO_CMD} ""

post-extract:
	${MKDIR} ${WRKDIR}/lens
	${MV} ${WRKDIR}/[A-Z]* ${WRKDIR}/lens
	${REINPLACE_CMD} 's|netscape|${WEB_BROWSER}|g' ${WRKSRC}/Src/lensrc.tcl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/FreeBSD/alens-2.63 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/FreeBSD/lens-2.63 ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/alens-2.63 ${PREFIX}/bin/alensnns
	${LN} -s ${PREFIX}/bin/lens-2.63 ${PREFIX}/bin/lensnns
	${INSTALL_MAN} ${WRKDIR}/lensnns.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/${PORTNAME}/Src/Images
	${MKDIR} ${PREFIX}/share/${PORTNAME}/Examples
	${MKDIR} ${PREFIX}/share/${PORTNAME}/Commands
	${INSTALL_DATA} ${WRKSRC}/Src/*.tcl \
		${PREFIX}/share/${PORTNAME}/Src
	${INSTALL_DATA} ${WRKSRC}/Src/Images/* \
		${PREFIX}/share/${PORTNAME}/Src/Images
	${INSTALL_DATA} ${WRKSRC}/Examples/* \
		${PREFIX}/share/${PORTNAME}/Examples
	${INSTALL_DATA} ${WRKSRC}/Commands/* \
		${PREFIX}/share/${PORTNAME}/Commands

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
