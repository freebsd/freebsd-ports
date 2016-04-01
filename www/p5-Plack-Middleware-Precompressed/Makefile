# $FreeBSD$

PORTNAME=	Plack-Middleware-Precompressed
PORTVERSION=	1.103
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARISTOTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to serve pre-gzipped content to capable clients

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Plack>0:www/p5-Plack \
	p5-Array-RefElem>0:misc/p5-Array-RefElem
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
