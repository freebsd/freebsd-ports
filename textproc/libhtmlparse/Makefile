# New ports collection makefile for:   libhtmlparse
# Date created:        1 January 2005
# Whom:                Mooneer Salem <mooneer@translator.cx>
#
# $FreeBSD$
#

PORTNAME=	libhtmlparse
PORTVERSION=	0.2.0
CATEGORIES=	textproc devel
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and fast HTML parsing library for C programs

BROKEN=		"mastersite disappeared"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2005-12-09

USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
