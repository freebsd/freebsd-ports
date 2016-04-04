# $FreeBSD$

PORTNAME=	Mail-Box-IMAP4-SSL
PORTVERSION=	0.03
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Missing part of Mail::Box::IMAP4

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Mail-Box>=0:mail/p5-Mail-Box \
		p5-superclass>=0.003:devel/p5-superclass \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Probe-Perl>=0:sysutils/p5-Probe-Perl \
		p5-Proc-Background>=1.08:devel/p5-Proc-Background

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
