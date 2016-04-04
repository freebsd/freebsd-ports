# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Net-Google-PicasaWeb
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Use Google Picasa Web API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Prompt>=0:devel/p5-IO-Prompt \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Role-Matcher>=0:devel/p5-MooseX-Role-Matcher \
		p5-Net-Google-AuthSub>=0:net/p5-Net-Google-AuthSub \
		p5-URI>=0:net/p5-URI \
		p5-XML-Twig>=3.30:textproc/p5-XML-Twig \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Able>=0.09:devel/p5-Test-Able \
		p5-Test-Able-Runner>=1.000:devel/p5-Test-Able-Runner \
		p5-Test-Mock-LWP>=0:devel/p5-Test-Mock-LWP

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
