# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-HTTP-LocalServer
PORTVERSION=	0.69
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Spawn a local HTTP server for testing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-HTTP-Daemon>=6.05:www/p5-HTTP-Daemon \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-HTTP-Request-AsCGI>=0:www/p5-HTTP-Request-AsCGI \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
