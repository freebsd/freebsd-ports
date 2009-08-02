# New ports collection makefile for:	kfile-plugins
# Date created:				11 Febrary 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${KFILEPLUGINS_PORTNAME}
PORTVERSION=	${KFILEPLUGINS_PORTVERSION}
PORTREVISION=	${KFILEPLUGINS_PORTREVISION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for Konqueror (in filemanager mode)

KDE_SPLIT=	${KFILEPLUGINS_PORTNAME:S/${KDE_SPLIT_DIST}-//}
KDE_DOC_SPLIT=	# none
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
.include <bsd.port.mk>
