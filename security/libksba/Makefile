# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	0.4.7
CATEGORIES=	security
MASTER_SITES= 	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/aegypten

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"KSBA is an X.509 Library"

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOCONF_VER=	253
USE_PERL5_BUILD=	yes

.include <bsd.port.mk>
