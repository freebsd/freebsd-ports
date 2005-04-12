# New ports collection makefile for:   libsrs2
# Date created:        02 July 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=		libsrs2
PORTVERSION=		1.0.18
CATEGORIES=		mail
MASTER_SITES=		http://www.libsrs2.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	srs

MAINTAINER=		mail-libsrs2-freebsd-ports@snowchyld.org
COMMENT=		Sender Rewriting Scheme 2 C Implementation

INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL_VER=	15

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
