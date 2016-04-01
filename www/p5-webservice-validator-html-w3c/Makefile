# Created by: toni.viemero@iki.fi
# $FreeBSD$

PORTNAME=	WebService-Validator-HTML-W3C
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Access to the W3Cs online HTML validator

RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-URI>=0:net/p5-URI \
		p5-XML-XPath>=0:textproc/p5-XML-XPath \
		p5-libwww>=0:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
