# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-Declare
PORTVERSION=	0.47
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perlish declarative templates

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
		p5-Class-ISA>0:devel/p5-Class-ISA \
		p5-HTML-Lint>0:www/p5-HTML-Lint \
		p5-String-BufferStack>=1.10:textproc/p5-String-BufferStack
TEST_DEPENDS=	p5-Test-Warn>=0.11:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
