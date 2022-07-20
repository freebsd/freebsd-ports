PORTNAME=	CSS-Squish
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compact many CSS files into one big file

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Test-LongString>=0:devel/p5-Test-LongString
RUN_DEPENDS=	p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
