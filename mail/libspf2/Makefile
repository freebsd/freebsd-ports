# New ports collection makefile for:   libspf2
# Date created:        07 July 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=		libspf2
PORTVERSION=		1.0.4
CATEGORIES=		mail
MASTER_SITES=		http://www.libspf2.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	spf

MAINTAINER=		mail-libspf2-freebsd-ports@snowchyld.org
COMMENT=		Sender Rewriting Scheme 2 C Implementation

INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL_VER=	15

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
