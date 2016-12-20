# $FreeBSD$

PORTNAME=	UML-Class-Simple
PORTVERSION=	0.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Render simple UML class diagrams, by loading the code

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Inspector>=1.16:devel/p5-Class-Inspector \
		p5-File-Slurp>0:devel/p5-File-Slurp \
		p5-IPC-Run3>0:devel/p5-IPC-Run3 \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-PPI>0:textproc/p5-PPI \
		p5-Template-Toolkit>0:www/p5-Template-Toolkit \
		p5-XML-LibXML>0:textproc/p5-XML-LibXML \
		p5-YAML-Syck>0:textproc/p5-YAML-Syck \
		dot:graphics/graphviz
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
