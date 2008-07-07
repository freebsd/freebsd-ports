# New ports collection makefile for:	linuxdcpp
# Date created:				19 June 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linuxdcpp
PORTVERSION=	1.0.2
CATEGORIES=	net-p2p
MASTER_SITES=	BERLIOS

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A port of the win32 DC++ direct connect client to POSIX-like systems

USE_BZIP2=	yes
USE_GNOME=	libglade2
USE_ICONV=	yes
USE_SCONS=	yes
USE_OPENSSL=	yes

SCONS_BUILDENV=	${SCONS_ENV}

.if defined(WITH_DEBUG)
SCONS_ARGS=	debug=1
.endif

.include <bsd.port.mk>
