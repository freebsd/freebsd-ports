# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines2
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.2
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the gtk+-2.0 toolkit

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack gtk20
PLIST_SUB=	VERSION=2.2.0

THEMES=		metal redmond95

post-patch:
	@for theme in ${THEMES}; do \
		cd ${WRKSRC}/$$theme/Theme/gtk-2.0; \
		${MV} gtkrc gtkrc.tmp; \
		${SED} -e s^%%PREFIX%%^${PREFIX}^g < gtkrc.tmp > gtkrc; \
	done

.include <bsd.port.mk>
