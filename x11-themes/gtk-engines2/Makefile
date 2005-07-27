# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines2
PORTVERSION=	2.6.4
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.6
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the gtk+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack gtk20
PLIST_SUB=	GTK_VERSION="2.4.0"

.if defined(WITH_ANIMATION)
CFLAGS+=	-DHAVE_ANIMATION=1
.endif

pre-everything::
.if !defined(WITH_ANIMATION)
	@${ECHO_MSG} ""
	@${ECHO_MSG} " You can enable experimental animated progressbars"
	@${ECHO_MSG} " with the clearlooks engine by defining"
	@${ECHO_MSG} " WITH_ANIMATION"
	@${ECHO_MSG} ""
.endif

# Disable the gtk1 theme.
post-patch:
	@${REINPLACE_CMD} -e 's|gtk gtk-2.0|gtk-2.0|g' \
		${WRKSRC}/themes/Redmond/Makefile.in

.include <bsd.port.mk>
