# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Email
PORTVERSION=	0.0002
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple email handling for Dancer2 applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer2>=0:www/p5-Dancer2 \
		p5-Email-Sender>=0:mail/p5-Email-Sender \
		p5-File-Type>=0:devel/p5-File-Type \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-WWW-Mechanize-PSGI>=0.35:devel/p5-Test-WWW-Mechanize-PSGI

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
