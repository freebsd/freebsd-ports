PORTNAME=	Markdown-Render
DISTVERSION=	2.0.4
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
RUN_DEPENDS=	p5-CLI-Simple>=1.0.11:devel/p5-CLI-Simple \
		p5-Class-Accessor>=0.51:devel/p5-Class-Accessor \
		p5-Config-Tiny>=2.30:devel/p5-Config-Tiny \
		p5-TimeDate>=2.24:devel/p5-TimeDate \
		p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
		p5-IO-Stringy>=2.113:devel/p5-IO-Stringy \
		p5-JSON>=4.10:converters/p5-JSON \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		p5-Readonly>0:devel/p5-Readonly

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
