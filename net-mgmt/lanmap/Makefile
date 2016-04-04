# $FreeBSD$

PORTNAME=	lanmap
DISTVERSION=	2006-03-07-rev81
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.parseerror.com/lanmap/rev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lanmap sits quietly on a network and builds a picture of what it sees

RUN_DEPENDS=	twopi:graphics/graphviz

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USES=		zip

post-extract:
	@${CHMOD} 755 ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
