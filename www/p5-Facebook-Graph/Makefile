PORTNAME=	Facebook-Graph
PORTVERSION=	1.1205
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIZEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to integrate your apps with Facebook

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0.61:devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=1.40,1:devel/p5-DateTime-Format-Strptime \
		p5-JSON>=2.16:converters/p5-JSON \
		p5-LWP-Protocol-https>=6.06:www/p5-LWP-Protocol-https \
		p5-MIME-Base64-URLSafe>=0.01:converters/p5-MIME-Base64-URLSafe \
		p5-Moo>=0:devel/p5-Moo \
		p5-Ouch>=0.0400:devel/p5-Ouch \
		p5-URI>=1.54:net/p5-URI \
		p5-libwww>=6.13:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
