PORTNAME=	PPIx-Regexp
DISTVERSION=	0.090
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	PPI regular expression parser
WWW=		https://metacpan.org/release/PPIx-Regexp

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSES/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSES/Copying

_BR_DEPENDS=	p5-PPI>=0:textproc/p5-PPI \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken
BUILD_DEPENDS=	${_BR_DEPENDS}
RUN_DEPENDS=	${_BR_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes
PORTSCOUT=	limit:^[^_]+$$

.include <bsd.port.mk>
