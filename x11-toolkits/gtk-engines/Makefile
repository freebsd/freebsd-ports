# New ports collection makefile for:	gtk-engines
# Date Created:				23 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines
PORTVERSION=	0.12
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gtk-engines/0.12

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for gtk+ toolkits

USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_LIBTOOL=	yes

THEMES=		metal notif pixmap raleigh redmond95

post-patch:
	@for theme in ${THEMES}; do \
		cd ${WRKSRC}/$$theme/Theme/gtk; \
		${MV} gtkrc gtkrc.tmp; \
		${SED} -e s^%%PREFIX%%^${PREFIX}^g < gtkrc.tmp > gtkrc; \
	done

.include <bsd.port.mk>
