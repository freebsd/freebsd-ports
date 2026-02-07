PORTNAME=	OpenTelemetry-Exporter-OTLP
PORTVERSION=	0.021
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JJATRIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	OpenTelemetry Protocol (OTLP) Exporter for Perl
WWW=		https://metacpan.org/dist/OpenTelemetry-Exporter-OTLP

LICENSE=	ART10

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

BR_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install
BUILD_DEPENDS=	${BR_DEPENDS} \
		p5-ExtUtils-MakeMaker>0:devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS=	${BR_DEPENDS} \
		p5-Feature-Compat-Try>0:devel/p5-Feature-Compat-Try \
		p5-File-Share>0:devel/p5-File-Share \
		p5-Future-AsyncAwait>=0.38:devel/p5-Future-AsyncAwait \
		p5-HTTP-Tiny>0:www/p5-HTTP-Tiny \
		p5-isa>0:devel/p5-isa \
		p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
		p5-Metrics-Any>0:devel/p5-Metrics-Any \
		p5-Object-Pad>=0.74:devel/p5-Object-Pad \
		p5-OpenTelemetry>=0.030:sysutils/p5-OpenTelemetry \
		p5-Path-Tiny>0:devel/p5-Path-Tiny \
		p5-Syntax-Keyword-Dynamically>0:devel/p5-Syntax-Keyword-Dynamically \
		p5-Syntax-Keyword-Match>0:devel/p5-Syntax-Keyword-Match \
		p5-Time-Piece>0:devel/p5-Time-Piece

.include <bsd.port.mk>
