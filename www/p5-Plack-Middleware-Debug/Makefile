# $FreeBSD$

PORTNAME=	Plack-Middleware-Debug
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to display information about current request/response

RUN_DEPENDS=	\
	p5-Class-Method-Modifiers>=1.05:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
	p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
	p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Text-MicroTemplate>=0.15:${PORTSDIR}/textproc/p5-Text-MicroTemplate \
	p5-Module-Versions>=0.01:${PORTSDIR}/devel/p5-Module-Versions
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
