# $FreeBSD$

PORTNAME=	Dancer-Plugin-Email
PORTVERSION=	1.0400
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple email handling for Dancer applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=0:www/p5-Dancer \
		p5-Email-Date-Format>=0:mail/p5-Email-Date-Format \
		p5-Email-Sender>=0:mail/p5-Email-Sender \
		p5-File-Type>=0:devel/p5-File-Type \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
