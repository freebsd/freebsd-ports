# Created by: will
# $FreeBSD$

PORTNAME=	Apache-AuthCookie
PORTVERSION=	3.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl module to provide custom forms for reauthentication

BUILD_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-autobox>=0:${PORTSDIR}/devel/p5-autobox \
		p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_APACHE=	22+

.include <bsd.port.pre.mk>

CURUSER?=	`whoami`
CURGRP?=	`groups | ${AWK} '{print $$1}'`
TESTPORT?=	8228
PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	APACHE="${HTTPD}" \
		TESTUSER="${CURUSER}" \
		TESTGRP="${CURGRP}" \
		TESTPORT="${TESTPORT}"

MAN3=		Apache2::AuthCookie.3 \
		Apache2::AuthCookie::Params.3 \
		Apache::AuthCookie.3 \
		Apache::AuthCookie::Autobox.3 \
		Apache::AuthCookie::FAQ.3 \
		Apache::AuthCookie::Params.3 \
		Apache::AuthCookie::Params::Base.3 \
		Apache::AuthCookie::Util.3

.include <bsd.port.post.mk>
