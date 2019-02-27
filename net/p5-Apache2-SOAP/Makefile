# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	Apache2-SOAP
PORTVERSION=	0.73
PORTREVISION=	4
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Apache2 mod_perl2 SOAP Server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2 \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite

USES=		apache:2.2+ perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
