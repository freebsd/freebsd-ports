# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.0.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

BUILD_DEPENDS+=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error
LIB_DEPENDS+=	gpg-error.0:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes

INFO=		ksba

.include <bsd.port.mk>
