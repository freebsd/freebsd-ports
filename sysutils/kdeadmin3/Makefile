# -*-mode: makefile-*-
# New ports collection makefile for:	kdeadmin
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeadmin
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	4
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE applications related to system administration

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool

USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e \
	's|pkgconfigdir =.*|pkgconfigdir = ${LOCALBASE}/libdata/pkgconfig|g' \
		${WRKSRC}/knetworkconf/backends/Makefile.in
	${REINPLACE_CMD} -e 's|INDEX-5|${INDEXFILE}|g' \
		${WRKSRC}/kpackage/fbsdInterface.cpp

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
