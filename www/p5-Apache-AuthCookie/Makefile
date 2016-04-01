# Created by: will
# $FreeBSD$

PORTNAME=	Apache-AuthCookie
PORTVERSION=	3.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to provide custom forms for reauthentication

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=1.39:www/mod_perl2 \
		p5-Class-Load>=0.03:devel/p5-Class-Load \
		p5-autobox>=1.10:devel/p5-autobox
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_APACHE=	22+
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

CURUSER?=	`whoami`
CURGRP?=	`groups | ${AWK} '{print $$1}'`
TESTPORT?=	8228
CONFIGURE_ENV+=	APACHE="${HTTPD}" \
		TESTUSER="${CURUSER}" \
		TESTGRP="${CURGRP}" \
		TESTPORT="${TESTPORT}"

.include <bsd.port.post.mk>
