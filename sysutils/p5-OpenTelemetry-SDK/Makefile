PORTNAME=	OpenTelemetry-SDK
PORTVERSION=	0.028
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JJATRIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	OpenTelemetry SDK for Perl
WWW=		https://metacpan.org/dist/OpenTelemetry-SDK/

LICENSE=	ART10

USES=		perl5
USE_PERL5=	modbuild

BUILD_DEPENDS=	p5-Module-Build-Tiny>0:devel/p5-Module-Build-Tiny
RUN_DEPENDS=	p5-Feature-Compat-Try>0:devel/p5-Feature-Compat-Try \
		p5-Future-AsyncAwait>=0.38:devel/p5-Future-AsyncAwait \
		p5-IO-Async>0:devel/p5-IO-Async \
		p5-isa>0:devel/p5-isa \
		p5-Metrics-Any>0:devel/p5-Metrics-Any \
		p5-Mutex>0:devel/p5-Mutex \
		p5-Object-Pad>=0.74:devel/p5-Object-Pad \
		p5-OpenTelemetry-Exporter-OTLP>0:sysutils/p5-OpenTelemetry-Exporter-OTLP \
		p5-OpenTelemetry>=0.030:sysutils/p5-OpenTelemetry

NO_ARCH=	yes

.include <bsd.port.mk>
