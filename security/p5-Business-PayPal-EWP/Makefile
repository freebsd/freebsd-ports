# Created by: Alfred Perlstein
# $FreeBSD$

PORTNAME=	Business-PayPal-EWP
PORTVERSION=	1.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Perl extension for PayPal Encrypted Website Payments

RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay

USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes
CONFIGURE_ARGS=	${OPENSSLBASE}
USE_DOS2UNIX=	yes

MAN3=	Business::PayPal::EWP.3

NO_STAGE=	yes
.include <bsd.port.mk>
