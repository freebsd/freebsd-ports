# New ports collection makefile for:	kicker-applets
# Date created:				11 Febrary 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${KICKERAPPLETS_PORTNAME}
PORTVERSION=	${KICKERAPPLETS_PORTVERSION}
PORTREVISION=	${KICKERAPPLETS_PORTREVISION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additional applets for Kicker

KDE_SPLIT=	${KICKERAPPLETS_PORTNAME:S/${KDE_SPLIT_DIST}-//}
USE_KDEBASE_VER=3
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
USE_AUTOTOOLS=  libtool:22
USE_GMAKE=	yes

USE_LDCONFIG=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/kde3

PLIST_SUB+=	KDE_VER="${KDE_VERSION}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libxmms.so)
LIB_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.endif

.include <bsd.port.post.mk>
