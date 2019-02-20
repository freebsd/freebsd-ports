# Created by: Matt Behrens <matt@zigg.com>
# $FreeBSD$

PORTNAME=	Authen-PAM
PORTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Perl interface to the PAM library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-DPAM_STRERROR_NEEDS_PAMH

.include <bsd.port.mk>
