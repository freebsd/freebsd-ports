# New ports collection makefile for:	beastie
# Date created:		2005-09-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/beastie/Makefile,v 1.3 2005/09/06 06:01:04 ahze Exp $
#

PORTNAME=	beastie
PORTVERSION=	05.07.11
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
DISTNAME=	Beastie-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gnome theme with FreeBSD Colors

WRKSRC=		${WRKDIR}/Beastie
USE_X_PREFIX=	yes
NO_BUILD=	yes

THEME_FILES=	README index.theme gtk-2.0/gtkrc
THEME_DIR=	share/themes/Beastie/
PLIST_FILES=	${THEME_FILES:S|^|${THEME_DIR}|}
PLIST_DIRS=	${THEME_DIR}/gtk-2.0 ${THEME_DIR}

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc)
WITH_GTKENGINES=	yes
.endif

.if !defined(WITHOUT_GTKENGINES) || defined(WITH_GTKENGINES)
RUN_DEPENDS+=	gtk-engines2>=2.6.4:${PORTSDIR}/x11-themes/gtk-engines2 \
		gnome-themes>=2.11.91:${PORTSDIR}/x11-themes/gnome-themes
.else
RUN_DEPENDS+=	clearlooks>=0.6.0:${PORTSDIR}/x11-themes/clearlooks \
		clearlooks-metacity>=0.6:${PORTSDIR}/x11-themes/clearlooks-metacity
.endif

pre-everything::
.if !defined(WITHOUT_GTKENGINES) && !defined(WITH_GTKENGINES)
	@${ECHO_MSG} "You can disable gtk-engines support (clearlooks)"
	@${ECHO_MSG} "and use x11-themes/clearlooks for the clearlooks"
	@${ECHO_MSG} "engine by defining"
	@${ECHO_MSG} "WITHOUT_GTKENGINES=yes"
.endif

do-install:
	${MKDIR} ${PREFIX}/${THEME_DIR}/gtk-2.0
.for f in ${THEME_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${THEME_DIR}/${f}
.endfor

.include <bsd.port.post.mk>
