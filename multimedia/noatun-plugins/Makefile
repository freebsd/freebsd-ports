# New ports collection makefile for:	noatun-plugins
# Date created:				11 Febrary 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${NOATUNPLUG_PORTNAME}
PORTVERSION=	${NOATUNPLUG_PORTVERSION}
PORTREVISION=	${NOATUNPLUG_PORTREVISION}
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Various plugins for Noatun

LIB_DEPENDS=	noatun:${PORTSDIR}/multimedia/kdemultimedia3

KDE_SPLIT=	${NOATUNPLUG_PORTNAME:S/${KDE_SPLIT_DIST}-//}
KDE_DOC_SPLIT=	# none
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"
.include <bsd.port.mk>
