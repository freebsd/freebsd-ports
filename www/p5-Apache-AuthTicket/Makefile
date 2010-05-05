# New ports collection makefile for:	Apache-AuthTicket
# Date created:				Sun Dec 31 19:57:53 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.90
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

RUN_DEPENDS=	${SITE_PERL}/Apache/AuthCookie.pm:${PORTSDIR}/www/p5-Apache-AuthCookie \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthTicket.3 Apache2::AuthTicket.3

USE_APACHE=	1.3+
.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} > 20
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif

.include <bsd.port.post.mk>
