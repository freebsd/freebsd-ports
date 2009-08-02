# New ports collection makefile for:	smpeg-xmms
# Date created:				30 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smpeg-xmms
PORTVERSION=	0.3.5
PORTREVISION=	8
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://www.xmms.org/files/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/%SUBDIR%/
MASTER_SITE_SUBDIR=	plugins/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mpeg video plugin for XMMS

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gnomehack gtk12
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	lib/xmms/Input/libsmpeg_xmms.so

# This is to avoid libtool running ldconfig -m ${LOCALBASE}/lib/xmms/Input
do-install:
	${MKDIR} ${PREFIX}/lib/xmms/Input
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/.libs/libsmpeg_xmms.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
