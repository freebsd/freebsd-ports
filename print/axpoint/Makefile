# Created by: ijliao
# $FreeBSD$

PORTNAME=	axpoint
PORTVERSION=	1.50
PORTREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSERGEANT
DISTNAME=	XML-Handler-AxPoint-${PORTVERSION:S/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML Based Presentations

BUILD_DEPENDS=	p5-Text-Iconv>=0:converters/p5-Text-Iconv \
		p5-Time-Piece>=1.08:devel/p5-Time-Piece \
		p5-XML-Filter-XSLT>=0:textproc/p5-XML-Filter-XSLT \
		p5-XML-SAX>=0.09:textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0.39:textproc/p5-XML-SAX-Writer \
		p5-PDFLib>=0.14:print/p5-PDFLib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
