# New ports collection makefile for:	gnomemimedata
# Date created:				22 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomemimedata
PORTVERSION=	1.0.1
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-mime-data
DISTNAME=	gnome-mime-data-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	giconv:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOMELIBS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
