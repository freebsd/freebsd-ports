# $FreeBSD$

PORTNAME=	HTTP-Session2
PORTVERSION=	1.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for HTTP session management

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Cookie-Baker>0:www/p5-Cookie-Baker \
	p5-Crypt-CBC>0:security/p5-Crypt-CBC \
	p5-Digest-HMAC>0:security/p5-Digest-HMAC \
	p5-Digest-SHA1>0:security/p5-Digest-SHA1 \
	p5-Mouse>0:devel/p5-Mouse
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
