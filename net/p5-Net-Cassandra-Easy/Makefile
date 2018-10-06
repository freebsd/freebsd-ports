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

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl \
		p5-Moose>=0:devel/p5-Moose

USES=		perl5 shebangfix
USE_PERL5=	configure
NO_ARCH=	yes

SHEBANG_FILES=	cassidy.pl genthrift.pl lib/Net/Cassandra/Easy.pm

.include <bsd.port.mk>
