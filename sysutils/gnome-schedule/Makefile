# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-schedule/Makefile,v 1.5 2007/09/10 06:20:14 mezz Exp $

PORTNAME=	gnome-schedule
PORTVERSION=	2.1.5
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME GUI for configuring a users crontab

LICENSE=	GPLv2

OPTIONS_DEFINE=	APPLET NLS
OPTIONS_DEFAULT=	APPLET
OPTIONS_SUB=	yes

BUILD_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USES=		gmake pathfix python
USE_GNOME=	gnomeprefix pygnome2
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

APPLET_CONFIGURE_ENABLE=	applet
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	--disable-nls

post-extract:
	@${RM} ${WRKSRC}/src/config.py

post-install:
	@${ECHO} "======================================================================"
	@${ECHO} "  To make one-time tasks work, add your username to /var/at/at.allow  "
	@${ECHO} "  Note that one-time tasks will never shows in ${PORTNAME}'s          "
	@${ECHO} "  task-list because of lacking FreeBSD's atq output format support.   "
	@${ECHO} "======================================================================"

.include <bsd.port.mk>
