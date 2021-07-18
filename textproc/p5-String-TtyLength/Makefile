# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	String-TtyLength
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate length of string excluding ANSI tty codes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Unicode-EastAsianWidth>=12.0:textproc/p5-Unicode-EastAsianWidth
TEST_DEPENDS=	p5-Test2-Suite>=0:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
