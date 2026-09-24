PORTNAME=	WebService-Linode
DISTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIKEGRB
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Interface to the Linode.com API
WWW=		https://metacpan.org/release/WebService-Linode

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Defunct service
EXPIRATION_DATE=	2026-10-24

BUILD_RUN_DEPENDS=	p5-JSON>=2.00:converters/p5-JSON \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
