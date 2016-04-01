# Created by: toni.viemero@iki.fi
# $FreeBSD$

PORTNAME=	WebService-Validator-CSS-W3C
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Experimental interface to the W3C CSS Validation online service

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
