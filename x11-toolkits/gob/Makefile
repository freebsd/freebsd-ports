# New ports collection makefile for:   GTK+ Object Builder
# Date created:        25 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gob
PORTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gob/1.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A preprocessor for making GTK+ objects with inline C

USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		gob.1

.include <bsd.port.mk>
