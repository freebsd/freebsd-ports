# Created by: Kay Abendroth <kay.abendroth@raxion.net>
# $FreeBSD$

PORTNAME=	Email-Reply
PORTVERSION=	1.204
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Email::Reply - Reply to a Message

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Abstract>=2.01:mail/p5-Email-Abstract \
		p5-Email-Address>=1.80:mail/p5-Email-Address \
		p5-Email-MIME>=1.82:mail/p5-Email-MIME
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
