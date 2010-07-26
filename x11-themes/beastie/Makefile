# New ports collection makefile for:	beastie
# Date created:		2005-09-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/beastie/Makefile,v 1.10 2006/07/18 11:56:12 ahze Exp $
#

PORTNAME=	beastie
PORTVERSION=	06.05.03
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~ahze/distfiles/
MASTER_SITE_SUBDIR=	ahze
DISTNAME=	Beastie-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome theme with FreeBSD Colors

RUN_DEPENDS+=	gtk-engines2>=2.7.4_1:${PORTSDIR}/x11-themes/gtk-engines2 \
		gnome-themes>=2.11.91:${PORTSDIR}/x11-themes/gnome-themes

WRKSRC=		${WRKDIR}/Beastie
NO_BUILD=	yes

THEME_FILES=	README index.theme gtk-2.0/gtkrc
THEME_DIR=	share/themes/Beastie/
PLIST_FILES=	${THEME_FILES:S|^|${THEME_DIR}|}
PLIST_DIRS=	${THEME_DIR}/gtk-2.0 ${THEME_DIR}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/${THEME_DIR}/gtk-2.0
.for f in ${THEME_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${THEME_DIR}/${f}
.endfor

.include <bsd.port.post.mk>
