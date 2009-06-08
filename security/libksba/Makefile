# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.0.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes

INFO=		ksba

.include <bsd.port.mk>
