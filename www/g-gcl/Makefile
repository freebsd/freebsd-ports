# New ports collection makefile for:	g-gcl
# Date created:				21 Jun 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	g-gcl
PORTVERSION=	1.10
CATEGORIES=	www graphics
MASTER_SITES=	http://www.whizkidtech.redprince.net/gcl/ \
		ftp://ftp.whizkidtech.redprince.net/cgi/gcl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sample counter scripts for Graphic Counter Language

RUN_DEPENDS=	gracula:${PORTSDIR}/graphics/gracula

NO_BUILD=

do-install:
	${MKDIR} ${PREFIX}/share/gracula
	${MKDIR} ${PREFIX}/share/gracula/pix
	${MKDIR} ${PREFIX}/share/examples/gracula
	${INSTALL_DATA} ${WRKSRC}/g.gd ${PREFIX}/share/gracula/pix
	${INSTALL_DATA} ${WRKSRC}/owl.gd ${PREFIX}/share/gracula/pix
	${INSTALL_DATA} ${WRKSRC}/read.gd ${PREFIX}/share/gracula/pix
	${INSTALL_DATA} ${WRKSRC}/space.gd ${PREFIX}/share/gracula/pix
	${INSTALL_SCRIPT} ${WRKSRC}/g.gcl.sample ${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/owl.gcl.sample ${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/read.gcl.sample ${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/space.gcl.sample ${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/sec2000.gcl.sample ${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/tri.gcl.sample ${PREFIX}/share/examples/gracula
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
