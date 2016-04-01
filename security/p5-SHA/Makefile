# Created by: Jim Geovedi <jim@corebsd.or.id>
# $FreeBSD$

PORTNAME=	SHA
PORTVERSION=	2.01
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GAAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the SHA1 algorithm

RUN_DEPENDS=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
