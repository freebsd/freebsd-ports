# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-vCard
PORTVERSION=	3.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Package to parse, edit and create multiple vCards (RFC 2426)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Moo>=0:devel/p5-Moo \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Text-vFile-asData>=0:devel/p5-Text-vFile-asData \
		p5-Unicode-LineBreak>=0:textproc/p5-Unicode-LineBreak \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Directory-Scratch>=0:devel/p5-Directory-Scratch \
		p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
