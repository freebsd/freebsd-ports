# $FreeBSD$

PORTNAME=	Email-MIME
PORTVERSION=	1.937
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy MIME message parsing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Simple>=2.206:mail/p5-Email-Simple \
		p5-Email-MessageID>=0:mail/p5-Email-MessageID \
		p5-Email-MIME-Encodings>=1.313:mail/p5-Email-MIME-Encodings \
		p5-Email-MIME-ContentType>=1.01.6:mail/p5-Email-MIME-ContentType \
		p5-MIME-Types>=1.13:mail/p5-MIME-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
