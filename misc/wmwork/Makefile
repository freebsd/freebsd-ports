# New ports collection makefile for:	wmwork
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmwork
PORTVERSION=	0.2.2
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmwork/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that keeps track of time you have spent on something

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	wmwork.1

CPPFLAGS=	-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lgnugetopt
.endif

.include <bsd.port.mk>
