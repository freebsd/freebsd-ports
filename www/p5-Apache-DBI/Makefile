# New ports collection makefile for:	p5-Apache-DBI
# Version required:			0.87
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

DISTNAME=	ApacheDBI-0.87
PKGNAME=	p5-Apache-DBI-0.87
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache

MAINTAINER=	igor@zynaps.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl

USE_PERL5=	YES

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Apache::DBI.3 \
		Apache::AuthDBI.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
