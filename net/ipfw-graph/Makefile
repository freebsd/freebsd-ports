# New ports collection makefile for:	ipfw-graph
# Date created:		16 November 2001
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	ipfw-graph
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Graphical overview of traffic going through your IPFW rules

USE_GNOME=	gtk12
MAKE_ENV+=	MANPREFIX="${MANPREFIX}"

MAN8=		ipfw-al.8 ipfw-graph.8

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/ipfw-graph.h

.include <bsd.port.mk>
