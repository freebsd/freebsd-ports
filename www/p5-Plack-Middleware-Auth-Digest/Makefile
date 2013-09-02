# New ports collection makefile for:	Plack::Middleware::Auth::Digest
# Date created:		03 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-Auth-Digest
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Plack extension for digest authentication

RUN_DEPENDS=	\
	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

MAN3=	Plack::Middleware::Auth::Digest.3

.include <bsd.port.mk>
