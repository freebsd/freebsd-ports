# New ports collection makefile for:	p5-Apache-DBI
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME?=	Apache-DBI
PORTVERSION=	1.06
PORTREVISION?=	1
CATEGORIES=	www databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT?=	DBI persistent connection, authentication and authorization

SLAVEDIRS=	www/p5-Apache-DBI-mp1 www/p5-Apache-DBI-mp2

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

MAKE_JOBS_SAFE=	yes

MAN3=		Apache::DBI.3 Apache::AuthDBI.3

PERL_CONFIGURE=	yes

.if defined(WITH_MODPERL2)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif

PLIST_FILES=	%%SITE_PERL%%/Apache/DBI.pm \
	%%SITE_PERL%%/Apache/AuthDBI.pm \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI/.packlist

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache \
	%%SITE_PERL%%/Apache

.include <bsd.port.mk>
