# New ports collection makefile for:	howl
# Date created:			21 July 2003
# Whom:				David Magda <dmagda+howl@ee.ryerson.ca>
# $FreeBSD$
#

PORTNAME=	howl
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES?=	net devel
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	paul@aps.org
COMMENT=	Zeroconf/Rendezvous implementation

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
