# New ports collection makefile for:	stress
# Date created:				18 May 2004
# Whom:					Dmitri Nikulin <setagllib@optusnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	stress
PORTVERSION=	0.18.1
CATEGORIES=	sysutils
MASTER_SITES=	http://weather.ou.edu/~apw/projects/stress/

MAINTAINER=	setagllib@optusnet.com.au
COMMENT=	Tool to impose load on and stress test Unix-like systems

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build ${MACHINE_ARCH}-portbld-freebsd${OSREL}

INFO=		stress
MAN1=		stress.1
PLIST_FILES=	bin/stress

.include <bsd.port.mk>
