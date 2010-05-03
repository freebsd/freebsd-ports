# New ports collection makefile for:	lanbrowsing
# Date created:				September 02 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lanbrowsing
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	6
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdenetwork-
DISTNAME=	kdenetwork-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lanbrowsing facility and backend for KDE

RUN_DEPENDS=	nmblookup:${PORTSDIR}/net/samba3

USE_KDELIBS_VER=3

USE_RC_SUBR=	lisa
USE_BZIP2=	yes
USE_XORG=	xtst

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdenetwork-${PORTVERSION}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure:
	${ECHO_CMD} ${PORTNAME} doc > ${WRKSRC}/inst-apps
	${REINPLACE_CMD} \
	's|^SUBDIRS =.*lisa.*$$|SUBDIRS =\. lisa|g' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/lanbrowsing/kcmlisa/main.cpp \
		${WRKSRC}/lanbrowsing/kcmlisa/kcmlisa.cpp \
		${WRKSRC}/lanbrowsing/kcmlisa/setupwizard.cpp
	${REINPLACE_CMD} -e 's|nmblookup \\|${LOCALBASE}/bin/nmblookup \\|g' \
		${WRKSRC}/lanbrowsing/lisa/netscanner.cpp

.include <bsd.port.post.mk>
