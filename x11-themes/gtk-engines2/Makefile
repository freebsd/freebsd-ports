# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-engines2/Makefile,v 1.59 2008/03/18 12:15:18 ahze Exp $
#

PORTNAME=	gtk-engines2
PORTVERSION=	2.14.3
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the gtk+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20 intlhack ltasneededhack
#USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

pre-everything::
.if !defined(WITH_ANIMATION)
	@${ECHO_MSG} ""
	@${ECHO_MSG} " You can enable experimental animated progressbars"
	@${ECHO_MSG} " with the clearlooks engine by defining"
	@${ECHO_MSG} " WITH_ANIMATION"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
