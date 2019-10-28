# Created by: Alex Perel <veers@disturbed.net>
# $FreeBSD$

PORTNAME=	MIME-Lite
PORTVERSION=	3.031
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple interface for creating (not parsing!) MIME messages

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Date-Format>=1.000:mail/p5-Email-Date-Format \
		p5-MIME-Types>=1.28:mail/p5-MIME-Types \
		p5-Mail-Tools>=1.62:mail/p5-Mail-Tools

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
