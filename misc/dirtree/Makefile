# ex:ts=8
# New ports collection makefile for:	dirtree
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dirtree
PORTVERSION=	1.2.0
CATEGORIES=	misc
MASTER_SITES=	http://members.chello.at/oberzalek/development/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	LeoArg:${PORTSDIR}/devel/leoarg \
		intl:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

MAN1=	dirtree.1

.include <bsd.port.mk>
