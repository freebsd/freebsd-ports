# New ports collection makefile for:	wmfsm
# Date created:				2 January 2001
# Whom:					Steven Enderle <panic@subphase.de>
#
# $FreeBSD$
#

PORTNAME=	wmfsm
PORTVERSION=	0.34
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.cs.ubc.ca/~cmg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays filesystem usage of mountpoints in a nice WindowMaker dockapp

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		wmfsm.1
PLIST_FILES=	bin/wmfsm

CPPFLAGS=	-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib

.include <bsd.port.mk>
