# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Date
PORTVERSION=	1.104
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find and Format Date Headers

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Email-Abstract>=2.10:mail/p5-Email-Abstract \
		p5-Email-Date-Format>=1:mail/p5-Email-Date-Format \
		p5-Email-Simple>=1.9:mail/p5-Email-Simple \
		p5-TimeDate>=1.16:devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
