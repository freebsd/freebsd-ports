# New ports collection makefile for:	Apache-AuthCookie
# Date created:				Sun Dec 31 19:55:36 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthCookie
PORTVERSION=	3.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl module to provide custom forms for reauthentication

.if defined(WITH_MODPERL2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
USE_APACHE=	2.0+
.else
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
USE_APACHE=	1.3
.endif

CURUSER?=	`whoami`
CURGRP?=	`groups | ${AWK} '{print $$1}'`
TESTPORT?=	8228
PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	APACHE="${HTTPD}" \
		TESTUSER="${CURUSER}" \
		TESTGRP="${CURGRP}" \
		TESTPORT="${TESTPORT}"

MAN3=		Apache::AuthCookie.3 Apache2::AuthCookie.3 Apache::AuthCookie::Util.3

.include <bsd.port.mk>
