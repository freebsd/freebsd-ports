# $FreeBSD$

PORTNAME=	Plack-Middleware-Session
PORTVERSION=	0.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for session management middleware for Plack

RUN_DEPENDS=	\
	p5-Cookie-Baker>0:${PORTSDIR}/www/p5-Cookie-Baker \
	p5-Digest-HMAC>=1.03:${PORTSDIR}/security/p5-Digest-HMAC \
	p5-Digest-SHA1>0:${PORTSDIR}/security/p5-Digest-SHA1 \
	p5-Plack>=0.9910:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Fatal>=0.006:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML

USES=	perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
