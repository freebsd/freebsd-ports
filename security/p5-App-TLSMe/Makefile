# $FreeBSD$

PORTNAME=	App-TLSMe
PORTVERSION=	0.110000
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0000$//}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for TLS/SSL tunnel

RUN_DEPENDS=	\
	p5-AnyEvent>=5.34:devel/p5-AnyEvent \
	p5-Net-SSLeay>0:security/p5-Net-SSLeay \
	p5-Proc-Pidfile>0:devel/p5-Proc-Pidfile
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
