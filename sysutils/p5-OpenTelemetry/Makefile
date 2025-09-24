PORTNAME=	OpenTelemetry
PORTVERSION=	0.031
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JJATRIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Perl implementation of the OpenTelemetry standard
WWW=		https://metacpan.org/pod/OpenTelemetry

LICENSE=	ART10

USES=		perl5
USE_PERL5=	modbuild

BUILD_DEPENDS=	p5-Module-Build-Tiny>0:devel/p5-Module-Build-Tiny
RUN_DEPENDS=	p5-Bytes-Random-Secure>0:security/p5-Bytes-Random-Secure \
		p5-Carp-Clan>0:devel/p5-Carp-Clan \
		p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers \
		p5-Exporter-Tiny>=0.044:devel/p5-Exporter-Tiny \
		p5-Feature-Compat-Defer>0:devel/p5-Feature-Compat-Defer \
		p5-Feature-Compat-Try>0:devel/p5-Feature-Compat-Try \
		p5-Future-AsyncAwait>0:devel/p5-Future-AsyncAwait \
		p5-Future>=0.26:devel/p5-Future \
		p5-isa>0:devel/p5-isa \
		p5-List-UtilsBy>0:devel/p5-List-UtilsBy \
		p5-Log-Any>0:devel/p5-Log-Any \
		p5-Module-Pluggable>0:devel/p5-Module-Pluggable \
		p5-Module-Runtime>0:devel/p5-Module-Runtime \
		p5-Mutex>0:devel/p5-Mutex \
		p5-Object-Pad>0:devel/p5-Object-Pad \
		p5-Ref-Util>0:devel/p5-Ref-Util \
		p5-Sentinel>0:devel/p5-Sentinel \
		p5-Syntax-Keyword-Dynamically>0:devel/p5-Syntax-Keyword-Dynamically \
		p5-URI>0:net/p5-URI \
		p5-URL-Encode>0:www/p5-URL-Encode \
		p5-UUID-URandom>0:devel/p5-UUID-URandom \
		p5-X-Tiny>0:devel/p5-X-Tiny

NO_ARCH=	yes

.include <bsd.port.mk>
