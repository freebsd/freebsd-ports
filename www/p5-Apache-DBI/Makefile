# New ports collection makefile for:	p5-Apache-DBI
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBI
PORTVERSION= 	0.87
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
DISTNAME=	ApacheDBI-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	igor@zynaps.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl

USE_PERL5=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Apache::DBI.3 \
		Apache::AuthDBI.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
