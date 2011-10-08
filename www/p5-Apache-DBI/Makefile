# New ports collection makefile for:	p5-Apache-DBI
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME?=	Apache-DBI
PORTVERSION=	1.11
CATEGORIES=	www databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT?=	DBI persistent connection, authentication and authorization

SLAVEDIRS=	www/p5-Apache-DBI-mp1 www/p5-Apache-DBI-mp2

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

MAKE_JOBS_SAFE=	yes

MAN3=		Apache::DBI.3 Apache::AuthDBI.3

PERL_CONFIGURE=	yes
USE_APACHE?=	13+

.include <bsd.port.pre.mk>

# prevent from direct including
# ports should use one of the SLAVEPORTS
.if !defined(PKGNAMESUFFIX)
IGNORE=		use ${SLAVEDIRS} instead
.endif

.if defined(WITH_MODPERL) && ${APACHE_VERSION} > 13
IGNORE=		mod_perl require apache13 but ${APACHE_PORT} is installed
.elif defined(WITH_MODPERL2) && ${APACHE_VERSION} < 20
IGNORE=		mod_perl2 require at last apache20 but ${APACHE_PORT} is installed
.endif

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

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI

PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache \
		%%SITE_PERL%%/Apache

.include <bsd.port.post.mk>
