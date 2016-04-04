# Created by: Andrea Venturoli <freebsd@netfence.it>
# $FreeBSD$

PORTNAME=	Mail-Field-Received
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl5 modules for parsing of `Received' headers in e-mails

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mail-Tools>0:mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Differences>0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
