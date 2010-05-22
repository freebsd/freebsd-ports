# New ports collection makefile for:	kaddressbook-plugins
# Date created:				11 Febrary 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${KADDRESSBOOKPLUG_PORTNAME}
PORTVERSION=	${KADDRESSBOOKPLUG_PORTVERSION}
PORTREVISION=	${KADDRESSBOOKPLUG_PORTREVISION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for KAdressbook

LIB_DEPENDS=	kdepim:${PORTSDIR}/deskutils/kdepim3
BUILD_DEPENDS=	kworldclock:${PORTSDIR}/x11-clocks/kdetoys3

KDE_SPLIT=	${KADDRESSBOOKPLUG_PORTNAME:S/${KDE_SPLIT_DIST}-//}
KDE_DOC_SPLIT=	# none
KDE_SPLIT_DIST=	kdeaddons
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
USE_AUTOTOOLS=  libtool:22
USE_GMAKE=	yes

USE_LDCONFIG=	yes

PLIST_SUB+=	KDE_VER="${KDE_VERSION}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"
.include <bsd.port.mk>
