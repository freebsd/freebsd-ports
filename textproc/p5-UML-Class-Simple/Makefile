# New ports collection makefile for:	textproc/p5-UML-Class-Simple
# Date created:				03 May 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	UML-Class-Simple
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	UML
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Render simple UML class diagrams, by loading the code

RUN_DEPENDS=	p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
		p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-IPC-Run3>0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Class-Inspector>=1.16:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		dot:${PORTSDIR}/graphics/graphviz
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	umlclass.pl.1
MAN3=	UML::Class::Simple.3

post-patch:
	${PERL} -pi -e '$$_="" if /auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
