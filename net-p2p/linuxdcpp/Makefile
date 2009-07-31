# New ports collection makefile for:	LinuxDC++
# Date created:				19 June 2005
# Whom:					Jeremy Messenger <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linuxdcpp
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_LOCAL} http://freebsd.nsu.ru/distfiles/
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A port of the DC++ direct connect client to POSIX-like systems

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
