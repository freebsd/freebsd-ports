# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Passphrase
PORTVERSION=	3.3.0
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Passphrases and Passwords as objects for Dancer2

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer2>=0.200000:www/p5-Dancer2 \
		p5-Data-Entropy>=0.005:security/p5-Data-Entropy \
		p5-Digest-Bcrypt>0:security/p5-Digest-Bcrypt \
		p5-Digest-SHA>=5.74:security/p5-Digest-SHA
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
