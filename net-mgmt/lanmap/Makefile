# $FreeBSD$

PORTNAME=	lanmap
DISTVERSION=	2006-03-07-rev81
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.parseerror.com/lanmap/rev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lanmap sits quietly on a network and builds a picture of what it sees

RUN_DEPENDS=	twopi:${PORTSDIR}/graphics/graphviz

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USES=		zip

NO_STAGE=	yes
.include <bsd.port.pre.mk>
post-extract:
	${CHMOD} 755 ${WRKSRC}/configure
.include <bsd.port.post.mk>
