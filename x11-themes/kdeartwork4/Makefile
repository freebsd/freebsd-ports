# -*-mode: makefile-*-
# New ports collection makefile for:	KDE artwork
# Date created:				20 August 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeartwork
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additional themes, sounds, wallpapers and window styles for KDE

USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}

USE_GL=		yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/xscreensaver)
WITH_XS=	yes
.endif # exists(${X11BASE}/bin/xscreensaver)

.if exists(${X11BASE}/share/gnome/control-center-2.0/capplets/screensaver-properties.desktop)
WITH_XSGNOME=	yes
.endif # exists(${X11BASE}/bin/screensaver-properties-capplet)

.if defined(WITH_XS) && !defined(WITH_XSGNOME)
RUN_DEPENDS+=	kxsconfig:${PORTSDIR}/x11/xscreensaver-kde
.endif # defined(WITH_XS)

.if defined(WITH_XSGNOME)
RUN_DEPENDS+=	kxsconfig:${PORTSDIR}/x11/xscreensaver-kde
.endif # defined(WITH_XSGNOME)

pre-configure:
	@${REINPLACE_CMD} -e 's|kxsconfig||g' ${WRKSRC}/kscreensaver/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's|.*XSCREENSAVER.*||g' ${WRKSRC}/config.h

.include <bsd.port.post.mk>
