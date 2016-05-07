# Created by: Gunter Wambaugh <gunter@six-two.net>
# $FreeBSD$

PORTNAME=	Net-Google-DataAPI
PORTVERSION=	0.28.01
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	gunter@six-two.net
COMMENT=	Base implementations for modules to negotiate with Google Data APIs

BUILD_DEPENDS=	p5-Any-Moose>=0.04:devel/p5-Any-Moose \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Lingua-EN-Inflect-Number>=0:textproc/p5-Lingua-EN-Inflect-Number \
		p5-Mouse>=0.51:devel/p5-Mouse \
		p5-Net-Google-AuthSub>=0.5:net/p5-Net-Google-AuthSub \
		p5-Net-OAuth>=0:net/p5-Net-OAuth \
		p5-Net-OAuth2>=0.07:net/p5-Net-OAuth2 \
		p5-Text-Glob>=0:textproc/p5-Text-Glob \
		p5-URI>=0:net/p5-URI \
		p5-XML-Atom>=0:textproc/p5-XML-Atom \
		p5-libwww>=0:www/p5-libwww \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockModule>=0:devel/p5-Test-MockModule \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
