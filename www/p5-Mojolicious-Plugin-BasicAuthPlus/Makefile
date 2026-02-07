PORTNAME=	Mojolicious-Plugin-BasicAuthPlus
PORTVERSION=	0.11.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Basic HTTP Auth Helper Plus
WWW=		https://metacpan.org/dist/Mojolicious-Plugin-BasicAuthPlus

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Authen-Simple>=0:security/p5-Authen-Simple \
		p5-Authen-Simple-Passwd>=0:security/p5-Authen-Simple-Passwd \
		p5-Mojolicious>=1.4:www/p5-Mojolicious \
		p5-perl-ldap>=0:net/p5-perl-ldap

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
