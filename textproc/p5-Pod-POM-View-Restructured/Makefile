PORTNAME=	Pod-POM-View-Restructured
PORTVERSION=	1.000004
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ALEXM
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	View for Pod::POM that outputs reStructuredText
WWW=		https://metacpan.org/release/Pod-POM-View-Restructured

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Pod-POM>=0:textproc/p5-Pod-POM

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
