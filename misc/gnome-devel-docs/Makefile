# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-devel-docs3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.6.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

USE_XZ=	yes
GNU_CONFIGURE=	yes
USES=		gmake shebangfix
USE_GNOME=	gnomehier gnomedocutils
INSTALLS_OMF=	yes
SHEBANG_FILES=	platform-demos/C/*/*.js platform-demos/C/*/*.py \
		platform-demos/C/samples/helloWorld/helloWorld
SHEBANG_LANG+=	gjs
gjs_OLD_CMD=	/usr/bin/gjs
gjs_CMD=	${LOCALBASE}/bin/gjs

.include <bsd.port.mk>
