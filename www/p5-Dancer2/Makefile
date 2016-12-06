# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer2
PORTVERSION=	0.204001
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight yet powerful web application framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Cmd>=0:devel/p5-App-Cmd \
		p5-Capture-Tiny>=0.12:devel/p5-Capture-Tiny \
		p5-Crypt-URandom>=0:security/p5-Crypt-URandom \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-ExtUtils-MakeMaker>=7.12:devel/p5-ExtUtils-MakeMaker \
		p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-HTTP-Body>=0:www/p5-HTTP-Body \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-HTTP-Headers-Fast>=0:www/p5-HTTP-Headers-Fast \
		p5-Import-Into>=0:devel/p5-Import-Into \
		p5-JSON>=0:converters/p5-JSON \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.000000:devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:devel/p5-MooX-Types-MooseLike \
		p5-Plack>=1.0035:www/p5-Plack \
		p5-Plack-Middleware-FixMissingBodyInRedirect>=0:www/p5-Plack-Middleware-FixMissingBodyInRedirect \
		p5-Plack-Middleware-RemoveRedundantBody>=0:www/p5-Plack-Middleware-RemoveRedundantBody \
		p5-Return-MultiLevel>=0:devel/p5-Return-MultiLevel \
		p5-Role-Tiny>=2.000000:devel/p5-Role-Tiny \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Template-Tiny>=0:textproc/p5-Template-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-YAML>=0.86:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-LWP-Protocol-PSGI>=0.06:www/p5-LWP-Protocol-PSGI \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-MockTime>=0:devel/p5-Test-MockTime \
		p5-YAML>=0.86:textproc/p5-YAML

OPTIONS_DEFINE=		XS
OPTIONS_DEFAULT=	XS

XS_BUILD_DEPENDS=	p5-CGI-Deurl-XS>=0:www/p5-CGI-Deurl-XS \
			p5-Class-Load-XS>=0:devel/p5-Class-Load-XS \
			p5-JSON-XS>=0:converters/p5-JSON-XS \
			p5-Scope-Upper>=0:devel/p5-Scope-Upper \
			p5-URL-Encode-XS>=0:www/p5-URL-Encode-XS \
			p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML
XS_RUN_DEPENDS=		${XS_BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
