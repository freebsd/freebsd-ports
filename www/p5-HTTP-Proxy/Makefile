# Created by: mat
# $FreeBSD$

PORTNAME=	HTTP-Proxy
PORTVERSION=	0.304
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl HTTP proxy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Daemon>=1.25:www/p5-HTTP-Daemon \
		p5-HTML-Parser>=3:www/p5-HTML-Parser \
		p5-libwww>=6:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
