# Ports collection makefile for:	p5-Pod-XML
# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	Pod-XML
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to convert POD to XML

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Test-File-Contents>=0:${PORTSDIR}/devel/p5-Test-File-Contents
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		pod2xml.1
MAN3=		Pod::XML.3

.include <bsd.port.mk>
