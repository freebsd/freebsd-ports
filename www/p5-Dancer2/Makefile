# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer2
PORTVERSION=	0.301001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight yet powerful web application framework

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0.12:devel/p5-Capture-Tiny \
		p5-Clone>=0:devel/p5-Clone \
		p5-Crypt-URandom>=0:security/p5-Crypt-URandom \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-File-Share>=0:devel/p5-File-Share \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-HTTP-Headers-Fast>=0.21:www/p5-HTTP-Headers-Fast \
		p5-HTTP-XSCookies>=0.000015:www/p5-HTTP-XSCookies \
		p5-Import-Into>=0:devel/p5-Import-Into \
		p5-JSON>=0:converters/p5-JSON \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.000000:devel/p5-Moo \
		p5-Plack>=1.0040:www/p5-Plack \
		p5-Plack-Middleware-FixMissingBodyInRedirect>=0:www/p5-Plack-Middleware-FixMissingBodyInRedirect \
		p5-Plack-Middleware-RemoveRedundantBody>=0:www/p5-Plack-Middleware-RemoveRedundantBody \
		p5-Ref-Util>=0:devel/p5-Ref-Util \
		p5-Return-MultiLevel>=0:devel/p5-Return-MultiLevel \
		p5-Role-Tiny>=2.000000:devel/p5-Role-Tiny \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Sub-Quote>=0:devel/p5-Sub-Quote \
		p5-Template-Tiny>=0:textproc/p5-Template-Tiny \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Type-Tiny>=1.000006:devel/p5-Type-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-YAML>=0.86:textproc/p5-YAML
TEST_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-LWP-Protocol-PSGI>=0.06:www/p5-LWP-Protocol-PSGI \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Test-CPAN-Meta>=0:devel/p5-Test-CPAN-Meta \
		p5-Test-EOL>=0:devel/p5-Test-EOL \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-MockTime>=0:devel/p5-Test-MockTime \
		p5-YAML>=0.86:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	XS
OPTIONS_DEFAULT=XS

XS_RUN_DEPENDS=	p5-CGI-Deurl-XS>=0:www/p5-CGI-Deurl-XS \
		p5-Class-Load-XS>=0:devel/p5-Class-Load-XS \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Scope-Upper>=0:devel/p5-Scope-Upper \
		p5-URL-Encode-XS>=0:www/p5-URL-Encode-XS \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

.include <bsd.port.mk>
