PORTNAME=	Template-Plugin-Filter-Minify-CSS-XS
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CSS::Minifier::XS filter for Template Toolkit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CSS-Minifier-XS>=0:textproc/p5-CSS-Minifier-XS \
		p5-Template-Toolkit>=2:www/p5-Template-Toolkit

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
