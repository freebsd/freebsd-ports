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
COMMENT=	Utilities for the KDE integrated X11 desktop

LIB_DEPENDS=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	kgpg-*

USE_KDELIBS_VER=3
USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
DO_NOT_COMPILE+=kmilo
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"

CONFLICTS=	kgpg-*

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

#klaptop needs APM, which is i386 only
.if ${MACHINE_ARCH} != "i386"
WITHOUT_KLAPTOP=yes
.endif

.if defined(WITHOUT_KLAPTOP)
DO_NOT_COMPILE+=klaptopdaemon
.else
PLIST_APPEND+=	plist.klaptop
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|#define HAVE_L_FUNCS 1||g' \
		${WRKSRC}/config.h

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
