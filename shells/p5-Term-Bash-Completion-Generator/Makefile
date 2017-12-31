# Created by: gebhart@secnetix.de
# $FreeBSD$

PORTNAME=	Term-Bash-Completion-Generator
PORTVERSION=	0.02.8
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gebhart@secnetix.de
COMMENT=	Generate bash completion scripts

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Readonly>=0:devel/p5-Readonly \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Tree-Trie>=0:devel/p5-Tree-Trie \
		p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Test-Block>=0:devel/p5-Test-Block \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
