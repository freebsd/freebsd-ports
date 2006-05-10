# New ports collection makefile for:	xpns
# Date created:         6 Apr 97
# Whom:                 Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	xpns
PORTVERSION=	1.0
CATEGORIES=	misc cad
MASTER_SITES=	http://robotics.ee.uwa.edu.au/pns/ftp/
DISTFILES=	pns_source.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Petri-Net Simulator for Xwindows

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
MAKEFILE=	makefile
ALL_TARGET=	pns

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xpns

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${PREFIX}/bin/xpns
	${MKDIR} ${PREFIX}/libexec/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${PREFIX}/libexec/xpns
	${MKDIR} ${PREFIX}/share/xpns
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${PREFIX}/share/xpns
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${PREFIX}/share/xpns
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xpns
	${INSTALL_DATA} ${WRKSRC}/*.net ${PREFIX}/share/doc/xpns
.endif

.include <bsd.port.mk>
