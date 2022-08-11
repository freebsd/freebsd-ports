PORTNAME=	Bot-Training-MegaHAL
PORTVERSION=	0.03
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AVAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide megahal.trn via Bot::Training

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-Bot-Training>=0:misc/p5-Bot-Training \
		p5-Moose>=0:devel/p5-Moose

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
