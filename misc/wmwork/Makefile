# New ports collection makefile for:	wmwork
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmwork
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmwork/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that keeps track of time you have spent on something

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		wmwork.1
PLIST_FILES=	bin/wmwork

CPPFLAGS=	-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib

.include <bsd.port.mk>
