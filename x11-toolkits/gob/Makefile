# New ports collection makefile for:   GTK+ Object Builder
# Date created:        25 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gob
PORTVERSION=	1.0.12
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A preprocessor for making GTK+ objects with inline C

DEPRECATED=	No more supported upstream, not depend on anymore.
EXPIRATION_DATE=	2011-12-03

USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		gob.1

.include <bsd.port.mk>
