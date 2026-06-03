PORTNAME=	Markdown-Render
DISTVERSION=	1.60.4
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BIGFOOT
PKGNAMEPREFIX=	p5-

MAINTAINER=	einar@isnic.is
COMMENT=	Render markdown as HTML
WWW=		https://metacpan.org/release/Markdown-Render

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ShareDir-Install>0:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Config-Tiny>0:devel/p5-Config-Tiny \
		p5-TimeDate>0:devel/p5-TimeDate \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-IO-Stringy>0:devel/p5-IO-Stringy \
		p5-JSON>0:converters/p5-JSON \
		p5-libwww>0:www/p5-libwww \
		p5-Readonly>0:devel/p5-Readonly

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
