# New ports collection makefile for:	konqueror-nsplugins
# Date created:				June 19 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	konqueror-nsplugins
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
PKGNAMEPREFIX=	kdebase-
DISTNAME=	kdebase-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Netscape plugin support for Konqueror

CONFLICTS=	kdebase-3.1.* kdebase-3.2.[0-3]

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_MOTIF=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdebase-${PORTVERSION}

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

pre-configure:
	${ECHO_CMD} "nsplugins" > ${WRKSRC}/inst-apps
	${REINPLACE_CMD} -e \
	's/startkde//g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
