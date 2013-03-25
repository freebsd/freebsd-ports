# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	xpns
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	misc cad
MASTER_SITES=	http://robotics.ee.uwa.edu.au/pns/ftp/
DISTNAME=	pns_source.tar
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Petri-Net Simulator for Xwindows

NO_WRKSUBDIR=	yes
USE_XORG=	x11 xaw
MAKEFILE=	makefile
ALL_TARGET=	pns

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xpns

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${PREFIX}/bin/xpns
	${MKDIR} ${PREFIX}/libexec/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${PREFIX}/libexec/xpns
	${MKDIR} ${PREFIX}/share/xpns
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${PREFIX}/share/xpns
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${PREFIX}/share/xpns
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/share/doc/xpns
	${INSTALL_DATA} ${WRKSRC}/*.net ${PREFIX}/share/doc/xpns
.endif

.include <bsd.port.mk>
