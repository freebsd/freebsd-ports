# New ports collection makefile for:   libspf2
# Date created:        07 July 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=		libspf2
PORTVERSION=		1.2.5
CATEGORIES=		mail
MASTER_SITES=		http://www.libspf2.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	spf

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		Sender Rewriting Scheme 2 C Implementation

CONFLICTS=		${PORTNAME}-1.0.*

INSTALLS_SHLIB=		yes
HAS_CONFIGURE=		yes
USE_LIBTOOL_VER=	15

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
