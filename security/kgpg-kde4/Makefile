# New ports collection makefile for:	kdeutils3
# Date created:				3 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeutils
PORTVERSION=	${KDE_VERSION}
CATEGORIES?=	misc kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		efax.1 efix.1 fax.1

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

#klaptop doesn't like alpha because alpha doesn't support apm
.if ${MACHINE_ARCH} == "alpha"
post-extract:
	mv ${WRKSRC}/subdirs ${WRKSRC}/subdirs.orig
	grep -v klaptopdaemon ${WRKSRC}/subdirs.orig > ${WRKSRC}/subdirs

PLIST_SUB+=	ALPHA_NA="@comment "
.else
PLIST_SUB+=	ALPHA_NA=""
.endif

.include <bsd.port.mk>
