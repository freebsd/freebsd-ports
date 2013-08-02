# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-String
PORTVERSION=	1.28
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to calculate with strings as if they were big integers

BUILD_DEPENDS=	p5-Math-BigInt>=1.87:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Math::String.3 \
		Math::String::Charset.3 \
		Math::String::Charset::Grouped.3 \
		Math::String::Charset::Nested.3 \
		Math::String::Sequence.3

.include <bsd.port.mk>
