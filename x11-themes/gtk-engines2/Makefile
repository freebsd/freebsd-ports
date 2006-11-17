# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-engines2/Makefile,v 1.29 2006/10/03 01:32:23 ahze Exp $
#

PORTNAME=	gtk-engines2
PORTVERSION=	2.8.2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.8
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the gtk+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtk20

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

# Disable the gtk1 theme.
post-patch:
	@${REINPLACE_CMD} -e 's|gtk gtk-2.0|gtk-2.0|g' \
		${WRKSRC}/themes/Redmond/Makefile.in

.include <bsd.port.mk>
