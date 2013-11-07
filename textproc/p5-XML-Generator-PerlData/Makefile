# Created by: Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
# $FreeBSD$

PORTNAME=	XML-Generator-PerlData
PORTVERSION=	0.91
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for generating SAX2 events from Perl data structures

BUILD_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
