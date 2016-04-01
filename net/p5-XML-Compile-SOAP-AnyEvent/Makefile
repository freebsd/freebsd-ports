# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-Compile-SOAP-AnyEvent
PORTVERSION=	0.90
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Exchange XML via AnyEvent::HTTP

BUILD_DEPENDS=	p5-AnyEvent-HTTP>=1.46:www/p5-AnyEvent-HTTP \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Log-Report>=1.05:devel/p5-Log-Report \
		p5-XML-Compile-SOAP>=3.05:net/p5-XML-Compile-SOAP
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
