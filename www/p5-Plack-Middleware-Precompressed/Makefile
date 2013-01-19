# $FreeBSD$

PORTNAME=	Plack-Middleware-Precompressed
PORTVERSION=	1.101
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARISTOTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to serve pre-gzipped content to capable clients

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Array-RefElem>0:${PORTSDIR}/misc/p5-Array-RefElem
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::Precompressed.3

.include <bsd.port.mk>
