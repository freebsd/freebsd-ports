# $FreeBSD$

PORTNAME=	UML-Class-Simple
PORTVERSION=	0.19
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Render simple UML class diagrams, by loading the code

BUILD_DEPENDS=	p5-Class-Inspector>=1.16:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-IPC-Run3>0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
		p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
