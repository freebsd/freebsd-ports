# New ports collection makefile for:	Apache-AuthCookie
# Date created:				Sun Dec 31 19:55:36 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthCookie
PORTVERSION=	2.011
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${APACHE_PORT}
RUN_DEPENDS=	${BUILD_DEPENDS}

APACHE_PORT?=	apache13
CURUSER?=	`whoami`
CURGRP?=	`groups | awk '{print $1}'`
TESTPORT?=	8228
PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	APACHE="${PREFIX}/sbin/apache" \
		TESTUSER="${CURUSER}" \
		TESTGRP="${CURGRP}" \
		TESTPORT="${TESTPORT}"

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::AuthCookie.3

.include <bsd.port.mk>
