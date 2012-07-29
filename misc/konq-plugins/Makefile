# New ports collection makefile for:	konq-plugins
# Date created:				11 February 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${KONQPLUGINS_PORTNAME}
PORTVERSION=	${KONQPLUGINS_PORTVERSION}
PORTREVISION=	${KONQPLUGINS_PORTREVISION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional plugins and features for Konqueror

KDE_SPLIT=	${KONQPLUGINS_PORTNAME:S/${KDE_SPLIT_DIST}-//}
USE_KDEBASE_VER=3
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
USE_AUTOTOOLS=  libtool
USE_GMAKE=	yes

USE_LDCONFIG=	yes

PLIST_SUB+=	KDE_VER="${KDE_VERSION}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"
.include <bsd.port.mk>
