# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	0.9.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/${PORTNAME}

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

LIB_DEPENDS=	gcrypt.12:${PORTSDIR}/security/libgcrypt \
		gpg-error.1:${PORTSDIR}/security/libgpg-error

GNU_CONFIGURE=	yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_PERL5_BUILD=yes

INFO=	ksba

.include <bsd.port.mk>
