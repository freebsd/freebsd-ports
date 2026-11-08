PORTNAME=	PodToHTML
DISTVERSION=	0.08
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Generating HTML from several files containing POD documentation
WWW=		https://metacpan.org/release/BDFOY/PodToHTML-0.08

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_RUN_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Format>=0:textproc/p5-HTML-Format

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
