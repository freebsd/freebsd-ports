PORTNAME=	Math-SymbolicX-Error
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parser extension for dealing with numeric errors

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Math-Symbolic>=0:math/p5-Math-Symbolic \
		p5-Math-SymbolicX-ParserExtensionFactory>=0:math/p5-Math-SymbolicX-ParserExtensionFactory \
		p5-Number-WithError>=0:math/p5-Number-WithError

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
