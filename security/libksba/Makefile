# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

BUILD_DEPENDS+=	libgpg-error>=1.10:${PORTSDIR}/security/libgpg-error
LIB_DEPENDS+=	gpg-error.0:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
WITH_FBSD10_FIX=yes

INFO=		ksba

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
