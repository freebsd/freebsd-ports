# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Table-Tiny
PORTVERSION=	1.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple text tables from 2D arrays, with limited templating options

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Ref-Util>=0.202:devel/p5-Ref-Util \
		p5-String-TtyLength>=0.02:textproc/p5-String-TtyLength
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
