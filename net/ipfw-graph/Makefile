# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	ipfw-graph
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Graphical overview of traffic going through your IPFW rules

USE_GNOME=	gtk12

MAN8=		ipfw-al.8 ipfw-graph.8

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/ipfw-graph.h

.include <bsd.port.mk>
