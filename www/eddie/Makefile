# New ports collection makefile for:	eddie
# Date created:		05-Jan-2001
# Whom:			Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	eddie
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.aims.com.au/chris/
DISTNAME=	eddie-1.5.1-20020619

MAINTAINER=	chris@aims.com.au

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang

USE_AUTOCONF=	yes
USE_GMAKE=	yes

BROKEN=	does not build with Erlang 9.0

.include <bsd.port.mk>
