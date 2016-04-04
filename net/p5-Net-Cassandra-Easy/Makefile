# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Cassandra-Easy
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perlish interface to the Cassandra database

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl \
		p5-Moose>=0:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	cassidy.pl genthrift.pl
USE_PERL5=	configure
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -i '' -e '1s|#!perl|#!${perl_CMD}|' ${WRKSRC}/lib/Net/Cassandra/Easy.pm

.include <bsd.port.mk>
