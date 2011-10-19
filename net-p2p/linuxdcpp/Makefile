# New ports collection makefile for:	LinuxDC++
# Date created:				19 June 2005
# Whom:					Jeremy Messenger <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linuxdcpp
PORTVERSION=	1.1.0
CATEGORIES=	net-p2p
MASTER_SITES=	http://launchpadlibrarian.net/69733951/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A port of the DC++ direct connect client to POSIX-like systems

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GNOME=	libglade2
USE_ICONV=	yes
USE_SCONS=	yes
USE_OPENSSL=	yes
PORTDOCS=	*

SCONS_BUILDENV=	${SCONS_ENV}

.if defined(WITH_DEBUG)
SCONS_ARGS=	debug=1
.endif

.include <bsd.port.mk>
