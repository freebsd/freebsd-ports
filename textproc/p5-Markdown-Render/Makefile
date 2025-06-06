PORTNAME=	Markdown-Render
PORTVERSION=	1.60.2
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BIGFOOT
PKGNAMEPREFIX=	p5-

MAINTAINER=	einar@isnic.is
COMMENT=	Render markdown as HTML
WWW=		https://metacpan.org/release/Markdown-Render

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.64:devel/p5-ExtUtils-MakeMaker \
		p5-File-ShareDir-Install>0:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-Class-Accessor>=0.51:devel/p5-Class-Accessor \
		p5-Config-Tiny>=2.28:devel/p5-Config-Tiny \
		p5-TimeDate>=2.24:devel/p5-TimeDate \
		p5-HTTP-Message>=6.45:www/p5-HTTP-Message \
		p5-IO-Stringy>=2.113:devel/p5-IO-Stringy \
		p5-JSON>=4.10:converters/p5-JSON \
		p5-libwww>=6.77:www/p5-libwww \
		p5-Readonly>=2.05:devel/p5-Readonly

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
