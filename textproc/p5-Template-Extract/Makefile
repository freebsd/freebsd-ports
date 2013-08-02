# Ports collection makefile for:	p5-Template-Extract
# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Template-Extract
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use TT2 syntax to extract data from documents

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Template::Extract.3 \
	Template::Extract::Compile.3 \
	Template::Extract::Parser.3 \
	Template::Extract::Run.3

.include <bsd.port.mk>
