# New ports collection makefile for:	Apache-AuthCookie
# Date created:				Sun Dec 31 19:55:36 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthCookie
PORTVERSION=	3.06
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl module to provide custom forms for reauthentication

RUN_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
.if defined(WITH_MODPERL2)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test

CURUSER?=	`whoami`
CURGRP?=	`groups | ${AWK} '{print $$1}'`
TESTPORT?=	8228
PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	APACHE="${PREFIX}/sbin/apache" \
		TESTUSER="${CURUSER}" \
		TESTGRP="${CURGRP}" \
		TESTPORT="${TESTPORT}"

MAN3=		Apache::AuthCookie.3

.include <bsd.port.mk>
