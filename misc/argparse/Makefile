# ex:ts=8
# New ports collection makefile for:	argparse
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argparse
PORTVERSION=	1.0.0
CATEGORIES=	misc
MASTER_SITES=	http://members.chello.at/oberzalek/development/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	LeoArg:${PORTSDIR}/devel/leoarg

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	argparse.1

.include <bsd.port.mk>
