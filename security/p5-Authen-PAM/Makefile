# New ports collection makefile for:    p5-Authen-PAM
# Version required:			0.08
# Date created:				Mon Oct  4 1999
# Whom:	      				Matt Behrens <matt@zigg.com>
#
# $FreeBSD$
#

DISTNAME=	Authen-PAM-0.08
PKGNAME=	p5-Authen-PAM-0.08
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen

MAINTAINER=	matt@zigg.com

USE_PERL5=	YES

MAN3=		Authen::PAM.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
