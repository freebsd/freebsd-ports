# New ports collection makefile for:    p5-Authen-PAM
# Date created:				Mon Oct  4 1999
# Whom:	      				Matt Behrens <matt@zigg.com>
#
# $FreeBSD$
#

PORTNAME=	Authen-PAM
PORTVERSION=	0.09
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	matt@zigg.com

USE_PERL5=	YES

MAN3=		Authen::PAM.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
