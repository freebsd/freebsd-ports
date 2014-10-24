# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	nos-ttb
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.djcbsoftware.nl/code/ttb/
DISTNAME=	ttb-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	NOS teletekst browser

#don't know if pygtk-1.X could also be used
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:${PORTSDIR}/x11-toolkits/py-gtk2

NO_BUILD=	yes
USES=		python

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ttb
	${INSTALL_SCRIPT} ${WRKSRC}/src/ttb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/glade/ttb.glade ${STAGEDIR}${PREFIX}/share/ttb
	${INSTALL_DATA} ${WRKSRC}/images/ttb.png ${STAGEDIR}${PREFIX}/share/ttb

.include <bsd.port.mk>
