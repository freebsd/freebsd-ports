# New ports collection makefile for:	kpilot
# Date created:				June 19 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kpilot
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	palm kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
PKGNAMEPREFIX=	kdepim-
DISTNAME=	kdepim-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Hotsync software for KDE

LIB_DEPENDS+=	mal:${PORTSDIR}/palm/libmal \
		pisock:${PORTSDIR}/palm/pilot-link

CONFLICTS=	kdepim-3.1.* kdepim-3.2.[0-3]

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/kdepim-${PORTVERSION}

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

pre-configure:
	${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	${ECHO_CMD} "libical libkcal kpilot doc" > ${WRKSRC}/inst-apps
	${REINPLACE_CMD} \
	's|^SUBDIRS =.*${PORTNAME}.*$$|SUBDIRS =\. ${PORTNAME}|g' \
		${WRKSRC}/doc/Makefile.in
post-configure:
	${REINPLACE_CMD} -e 's|^install: install-recursive|install:|g' \
		${WRKSRC}/libkcal/Makefile

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
