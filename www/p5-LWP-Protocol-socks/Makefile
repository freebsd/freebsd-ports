PORTNAME=	LWP-Protocol-socks
DISTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Adds support for the socks protocol and proxy facility in LWP
WWW=		https://metacpan.org/release/LWP-Protocol-socks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-Socks>=0:net/p5-IO-Socket-Socks \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
