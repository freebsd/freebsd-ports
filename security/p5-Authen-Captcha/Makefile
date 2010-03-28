# New ports collection makefile for:	Authen-Captcha
# Date created:				Mon May 10 13:27:28 CEST 2004
# Whom:					tobez@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Authen-Captcha
PORTVERSION=	1.023
PORTREVISION=	7
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to verify the human element in transactions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Authen::Captcha.3

.include <bsd.port.mk>
