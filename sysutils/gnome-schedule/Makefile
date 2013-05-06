# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-schedule/Makefile,v 1.5 2007/09/10 06:20:14 mezz Exp $

PORTNAME=	gnome-schedule
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME GUI for configuring a users crontab

LICENSE=	GPLv2

BUILD_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack pygnome2
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes

.if  !defined(WITHOUT_APPLET)
CONFIGURE_ARGS+=	--enable-applet
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=	--disable-applet
PLIST_SUB+=	APPLET="@comment "
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${RM} ${WRKSRC}/src/config.py

post-install:
	@${ECHO} "======================================================================"
	@${ECHO} "  To make one-time tasks work, add your username to /var/at/at.allow  "
	@${ECHO} "  Note that one-time tasks will never shows in ${PORTNAME}'s          "
	@${ECHO} "  task-list because of lacking FreeBSD's atq output format support.   "
	@${ECHO} "======================================================================"

.include <bsd.port.mk>
