PORTNAME=	Dancer2-Plugin-Path-Class
DISTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HVOERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	List a directory using Path::Class
WWW=		https://metacpan.org/release/HVOERS/Dancer2-Plugin-Path-Class-0.08

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_RUN_DEPENDS=	p5-Dancer2>=0.166000:www/p5-Dancer2 \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Format-Human-Bytes>=0:converters/p5-Format-Human-Bytes
TEST_DEPENDS=	p5-Path-Tiny>=0:devel/p5-Path-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
