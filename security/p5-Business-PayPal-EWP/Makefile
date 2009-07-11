# New ports collection makefile for:   p5-Business-PayPal-EWP
# Date created:                        Thu 12 May 2005
# Whom:                                Alfred Perlstein
#
#
# $FreeBSD$
#

PORTNAME=	Business-PayPal-EWP
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Perl extension for PayPal Encrypted Website Payments

RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay

PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	${OPENSSLBASE}
USE_UNIX2DOS=	yes

MAN3=	Business::PayPal::EWP.3

.include <bsd.port.mk>
