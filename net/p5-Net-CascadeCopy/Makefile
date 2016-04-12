# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-CascadeCopy
PORTVERSION=	0.2.6
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Rapidly propagate files to many servers in multiple locations

BUILD_DEPENDS=	p5-Class-Std-Utils>=v0.0.0:devel/p5-Class-Std-Utils \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Proc-Queue>=0:devel/p5-Proc-Queue
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
