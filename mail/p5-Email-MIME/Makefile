# $FreeBSD$

PORTNAME=	Email-MIME
PORTVERSION=	1.949
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy MIME message parsing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Address-XS>=0:mail/p5-Email-Address-XS \
		p5-Email-MIME-ContentType>=1.023:mail/p5-Email-MIME-ContentType \
		p5-Email-MIME-Encodings>=1.314:mail/p5-Email-MIME-Encodings \
		p5-Email-MessageID>=0:mail/p5-Email-MessageID \
		p5-Email-Simple>=2.212:mail/p5-Email-Simple \
		p5-MIME-Types>=1.13:mail/p5-MIME-Types \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
