PORTNAME=	Jq
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl binding to the jq data language
WWW=		https://metacpan.org/dist/Jq

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-JSON>=0:converters/p5-JSON \
		jq:textproc/jq

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
