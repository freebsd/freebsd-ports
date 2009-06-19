# New ports collection makefile for:	lensnns
# Date created:		9 jan 2007
# Whom:			Jason W. Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	lensnns
PORTVERSION=	2.63
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://tedlab.mit.edu/~dr/Lens/Dist/ \
		http://www.neuro.mcw.edu/Ports/distfiles/
DISTNAME=	lens

MAINTAINER=	jwbacon@tds.net
COMMENT=	Light Efficient Neural Network Simulator

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	runsomebrowser:${PORTSDIR}/www/runsomebrowser

USE_GMAKE=	yes

MAN1=		lensnns.1

SUB_FILES=	pkg-message lensnns.1 lensnns.cshrc lensnns.profile
PKGMESSAGE=	${WRKDIR}/pkg-message
WEB_BROWSER?=	runsomebrowser
MAKE_ENV+=	HOSTTYPE="FreeBSD"

post-extract:
	${MKDIR} ${WRKDIR}/lens
	${MV} ${WRKDIR}/[A-Z]* ${WRKDIR}/lens
	${REINPLACE_CMD} 's|netscape|${WEB_BROWSER}|g' ${WRKSRC}/Src/lensrc.tcl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/FreeBSD/alens-2.63 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/FreeBSD/lens-2.63 ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/alens-2.63 ${PREFIX}/bin/alensnns
	${LN} -s ${PREFIX}/bin/lens-2.63 ${PREFIX}/bin/lensnns
	${INSTALL_MAN} ${WRKDIR}/lensnns.1 ${MAN1PREFIX}/man/man1
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
	${MKDIR} ${PREFIX}/etc/mri
	${INSTALL_SCRIPT} ${WRKDIR}/lensnns.cshrc ${WRKDIR}/lensnns.profile \
		${PREFIX}/etc/mri

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
