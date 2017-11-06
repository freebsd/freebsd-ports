# Created by: Steven Kreuzer
# $FreeBSD$

PORTNAME=	Business-PayPal
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for automating PayPal transactions

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Net-SSLeay>=1.35:security/p5-Net-SSLeay \
		p5-CGI>=3.49:www/p5-CGI
BUILD_DEPENDS:=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
