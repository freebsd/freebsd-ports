# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gracula
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gracula/pix
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/gracula
	${INSTALL_DATA} ${WRKSRC}/g.gd ${STAGEDIR}${PREFIX}/share/gracula/pix
	${INSTALL_DATA} ${WRKSRC}/owl.gd ${STAGEDIR}${PREFIX}/share/gracula/pix
	${INSTALL_DATA} ${WRKSRC}/read.gd ${STAGEDIR}${PREFIX}/share/gracula/pix
	${INSTALL_DATA} ${WRKSRC}/space.gd ${STAGEDIR}${PREFIX}/share/gracula/pix
	${INSTALL_SCRIPT} ${WRKSRC}/g.gcl.sample ${STAGEDIR}${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/owl.gcl.sample ${STAGEDIR}${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/read.gcl.sample ${STAGEDIR}${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/space.gcl.sample ${STAGEDIR}${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/sec2000.gcl.sample ${STAGEDIR}${PREFIX}/share/examples/gracula
	${INSTALL_SCRIPT} ${WRKSRC}/tri.gcl.sample ${STAGEDIR}${PREFIX}/share/examples/gracula

.include <bsd.port.mk>
