# New ports collection makefile for:	gtk-engines
# Version required:			0.1
# Date Created:				23 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1999/01/31 16:59:44 vanilla Exp $
#

DISTNAME=	gtk-engines-0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gtk-engines

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gdk_imlib.2:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11d-config"

THEMES=		metal notif pixmap redmond95

post-patch:
	@for theme in ${THEMES}; do \
		cd ${WRKSRC}/$$theme/Theme/gtk; \
		${MV} gtkrc gtkrc.tmp; \
		${SED} -e s^%%PREFIX%%^${PREFIX}^g < gtkrc.tmp > gtkrc; \
	done

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
