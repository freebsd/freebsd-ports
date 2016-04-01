# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Message
PORTVERSION=	6.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Representation of HTTP style messages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Encode-Locale>=1:converters/p5-Encode-Locale \
		p5-HTTP-Date>=6:www/p5-HTTP-Date \
		p5-IO-HTML>=0:devel/p5-IO-HTML \
		p5-LWP-MediaTypes>=6:www/p5-LWP-MediaTypes \
		p5-URI>=1.10:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/HTTP/Headers.pm.orig

.include <bsd.port.mk>
