# New ports collection makefile for:	gnome-themes-extras
# Date Created:				12 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes-extras/Makefile,v 1.10 2006/03/02 21:18:34 mezz Exp $
#

PORTNAME=	gnome-themes-extras
PORTVERSION=	0.9.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.9
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	More themes for the GNOME 2 desktop environment

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgnomeui intlhack
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503001
EXTRACT_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		"/^themedir =.*metacity-1$$/s|themes|gnome/themes|"

.include <bsd.port.post.mk>
