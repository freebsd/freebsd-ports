# Created by: Matt Behrens <matt@zigg.com>
# $FreeBSD$

PORTNAME=	Authen-PAM
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	A Perl interface to the PAM library

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-DPAM_STRERROR_NEEDS_PAMH

MAN3=		Authen::PAM.3 \
		Authen::PAM::FAQ.3

.include <bsd.port.mk>
