# New ports collection makefile for:	TacacsPlus
# Date created:				Mon Jan  1 04:34:25 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	TacacsPlus
PORTVERSION=	0.16
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes
PERL_CONFIGURE=	yes
MAKE_ENV+=	CCFLAGS="${CFLAGS}"

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-build:
	${PERL} -pi -e "s:CCFLAGS =:CCFLAGS ?=:g" ${WRKSRC}/tacpluslib/Makefile

.include <bsd.port.mk>
