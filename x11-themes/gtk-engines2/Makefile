# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/x11-themes/gtk-engines2/Makefile,v 1.1 2006/03/13 22:39:57 mezz Exp $
#

PORTNAME=	gtk-engines2
PORTVERSION=	2.6.8
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the gtk+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtk20

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
