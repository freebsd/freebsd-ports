# New ports collection makefile for:	ipfw-graph
# Date created:		16 November 2001
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	ipfw-graph
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org

USE_GTK=	yes
MAKE_ENV+=	MANPREFIX="${MANPREFIX}"

MAN8=		ipfw-al.8 ipfw-graph.8

pre-patch:
	@${PERL} -pi -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/ipfw-graph.h

.include <bsd.port.mk>
