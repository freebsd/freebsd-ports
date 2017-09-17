# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	dummyflash
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netscape.com/pub/sdk/plugin/unix/
DISTNAME=	unix-sdk-3.0b5

MAINTAINER=	darius@dons.net.au
COMMENT=	Silently consume flash MIME types

USE_XORG=	x11
BUILD_WRKSRC=	${WRKSRC}/PluginSDK30b5/examples/UnixTemplate/Unix
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.freebsd

USES=		webplugin:native tar:Z
WEBPLUGIN_FILES=dummyflash.so

USE_HARDENING=	pie:off relro:off

do-install:
	@${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/dummyflash.so ${STAGEDIR}${WEBPLUGIN_DIR}

.include <bsd.port.mk>
