# New ports collection makefile for:	textproc/p5-UML-Class-Simple
# Date created:				03 May 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	UML-Class-Simple
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
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
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	umlclass.pl.1
MAN3=	UML::Class::Simple.3

post-patch:
	${PERL} -pi -e '$$_="" if /auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
