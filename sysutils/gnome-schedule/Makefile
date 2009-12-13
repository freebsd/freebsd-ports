# New ports collection makefile for:	gnome-schedule
# Date created:		2004-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-schedule/Makefile,v 1.5 2007/09/10 06:20:14 mezz Exp $
#

PORTNAME=	gnome-schedule
PORTVERSION=	2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME GUI for configuring a users crontab

BUILD_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack pygnome2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes

post-extract:
	@${RM} ${WRKSRC}/src/config.py

.include <bsd.port.mk>
