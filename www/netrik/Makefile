# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	netrik
# Date created:		2002-12-23
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netrik
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		netrik.1
MAN5=		netrikrc.5

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lgnugetopt
.endif

.include <bsd.port.mk>
