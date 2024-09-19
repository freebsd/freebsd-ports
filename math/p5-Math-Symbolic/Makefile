PORTNAME=	Math-Symbolic
PORTVERSION=	0.613
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Symbolic calculations
WWW=		https://metacpan.org/release/Math-Symbolic

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	compile_yapp_parser.pl

.include <bsd.port.mk>
