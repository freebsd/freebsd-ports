# New ports collection makefile for:	gtk-engines
# Date Created:				23 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/gtk-engines/Makefile,v 1.1 2006/07/18 16:32:36 ahze Exp $

PORTNAME=	gtk-engines
PORTVERSION=	0.12
PORTREVISION=	9
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for gtk+ toolkits

USE_GNOME=	imlib
GNU_CONFIGURE=	yes

THEMES=		metal notif pixmap raleigh redmond95

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig
	@for theme in ${THEMES}; do \
		cd ${WRKSRC}/$$theme/Theme/gtk; \
		${MV} gtkrc gtkrc.tmp; \
		${SED} -e s^%%PREFIX%%^${PREFIX}^g < gtkrc.tmp > gtkrc; \
	done

.include <bsd.port.mk>
