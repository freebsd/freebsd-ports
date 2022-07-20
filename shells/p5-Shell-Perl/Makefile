PORTNAME=	Shell-Perl
PORTVERSION=	0.0040
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|0$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read-eval-print loop in Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Data-Dump-Streamer>=0:devel/p5-Data-Dump-Streamer \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Expect>=0:devel/p5-Test-Expect \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Script>=0:devel/p5-Test-Script

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
