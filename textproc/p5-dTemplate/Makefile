# New ports collection makefile for: p5-dTemplate
# Date created:			9 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	dTemplate
PORTVERSION=	1.0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	dTemplate
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeremy@external.org

MAN3=		dTemplate.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
