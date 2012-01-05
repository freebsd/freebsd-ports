# New ports collection makefile for:	p5-Apache-DBI
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBI
PORTVERSION=	1.11
CATEGORIES=	www databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI persistent connection, authentication and authorization

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-Apache-DBI-mp[12]*

MAKE_JOBS_SAFE=	yes

MAN3=		Apache::DBI.3 Apache::AuthDBI.3

PERL_CONFIGURE=	yes
USE_APACHE?=	20+

.include <bsd.port.pre.mk>

PLIST_FILES=	%%SITE_PERL%%/Apache/DBI.pm \
		%%SITE_PERL%%/Apache/AuthDBI.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI/.packlist

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI

PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache \
		%%SITE_PERL%%/Apache

.include <bsd.port.post.mk>
