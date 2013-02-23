# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	IO-Async-SSL
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use SSL/TLS with IO::Async

BUILD_DEPENDS=	p5-IO-Async>=0.29:${PORTSDIR}/devel/p5-IO-Async\
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::Async::SSL.3 \
		IO::Async::SSLStream.3

.include <bsd.port.mk>
