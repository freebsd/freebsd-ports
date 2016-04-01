# Created by: mat
# $FreeBSD$

PORTNAME=	HTTP-Request-Params
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve GET/POST Parameters from HTTP Requests

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.19:devel/p5-Class-Accessor \
		p5-Email-MIME-ContentType>=1:mail/p5-Email-MIME-ContentType \
		p5-Email-MIME>=1.420:mail/p5-Email-MIME \
		p5-HTTP-Message>=1.40:www/p5-HTTP-Message
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200
BUILD_DEPENDS+=	p5-CGI>=3:www/p5-CGI
RUN_DEPENDS+=	p5-CGI>=3:www/p5-CGI
.endif

.include <bsd.port.post.mk>
