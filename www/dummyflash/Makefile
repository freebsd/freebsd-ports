# New ports collection makefile for:	dummyflash
# Date Created:				June 16 2004
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	dummyflash
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netscape.com/pub/sdk/plugin/unix/
DISTNAME=	unix-sdk-3.0b5
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	darius@dons.net.au
COMMENT=	Silently consume flash MIME types

USE_X_PREFIX=	yes
BUILD_WRKSRC=	${WRKSRC}/PluginSDK30b5/examples/UnixTemplate/Unix
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.freebsd

do-install:
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_DATA} ${BUILD_WRKSRC}/dummyflash.so ${PREFIX}/lib/browser_plugins

.include <bsd.port.mk>
