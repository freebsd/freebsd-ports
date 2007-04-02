# New ports collection makefile for:	linuxdcpp
# Date created:				19 June 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linuxdcpp
PORTVERSION=	0.0.1.20070324	#0.0.1.YYYYMMDD
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~mezz/distfiles/
MASTER_SITE_SUBDIR=mezz

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A port of the win32 DC++ direct connect client to POSIX-like systems

USE_XLIB=	yes
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
