# New ports collection makefile for:	kdebase2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeedu
PORTVERSION=	3.0
CATEGORIES?=	misc kde
MASTER_SITES=	http://www.csociety.org/~will/kde/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

#WRKSRC=		${WRKDIR}/kdeedu
USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

.include <bsd.port.mk>
