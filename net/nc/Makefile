# New ports collection makefile for:	nc
# Date created:			Apr 27, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	nc
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file
DISTNAME=	ncat-${PORTVERSION}

MAINTAINER=	markp@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
MAN1=		ncat.1

.include <bsd.port.mk>
