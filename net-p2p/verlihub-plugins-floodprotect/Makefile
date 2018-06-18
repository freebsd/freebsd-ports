# Created by: Mikle Davidkin <skylord@vt.net.ru>
# $FreeBSD$

PORTNAME=	floodprotect
PORTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF/verlihub/OldFiles
DISTNAME=	${PLUGIN_NAME}

MAINTAINER=	me@skylord.ru

BROKEN_powerpc64=	fails to compile: thasharray.h:338:29: cast from 'std::nullptr_t' to 'short int' loses precision

PLUGIN_NAME=	floodprot
PLUGIN_DESC=	Floodprotect

# Bug 219281: the port fails to build in C++14 mode (the default in GCC 6),
# switch back to the old default GCC used before.
USE_CXXSTD=	gnu++03

.include "../verlihub-plugins/Makefile.plugins"
.include <bsd.port.mk>
