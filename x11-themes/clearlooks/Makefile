# New ports collection makefile for:	clearlooks
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clearlooks
PORTVERSION=	0.5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clearlooks

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GTK+ 2.x engine based on Bluecurve

USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gtk20 gnomehier
USE_X_PREFIX=	yes


CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

OPTIONS=	METACITY "Depend on MetaCity Theme" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_METACITY)
RUN_DEPENDS+=	${X11BASE}/share/gnome/themes/Clearlooks/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/clearlooks-metacity
.endif

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

.include <bsd.port.post.mk>
