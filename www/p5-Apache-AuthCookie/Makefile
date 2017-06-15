# Created by: will
# $FreeBSD$

PORTNAME=	Apache-AuthCookie
PORTVERSION=	3.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to provide custom forms for reauthentication

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=1.39:www/mod_perl2 \
		p5-Class-Load>=0.03:devel/p5-Class-Load \
		p5-Hash-MultiValue>=0:devel/p5-Hash-MultiValue \
		p5-HTTP-Body>=0:www/p5-HTTP-Body \
		p5-WWW-Form-UrlEncoded>=0:www/p5-WWW-Form-UrlEncoded
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-URI>=1.71:net/p5-URI

NO_ARCH=	yes
USE_APACHE=	22+
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

CURUSER?=	`whoami`
CURGRP?=	`groups | ${AWK} '{print $$1}'`
TESTPORT?=	8228
CONFIGURE_ENV+=	APACHE="${HTTPD}" \
		TESTUSER="${CURUSER}" \
		TESTGRP="${CURGRP}" \
		TESTPORT="${TESTPORT}"

.include <bsd.port.post.mk>
