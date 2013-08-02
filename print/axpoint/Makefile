# ex:ts=8
# Ports collection makefile for:	axpoint
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axpoint
PORTVERSION=	1.50
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSERGEANT
DISTNAME=	XML-Handler-AxPoint-${PORTVERSION:S/0$//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Based Presentations

BUILD_DEPENDS=	p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv \
		p5-Time-Piece>=1.08:${PORTSDIR}/devel/p5-Time-Piece \
		p5-XML-Filter-XSLT>=0:${PORTSDIR}/textproc/p5-XML-Filter-XSLT \
		p5-XML-SAX>=0.09:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0.39:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-PDFLib>=0.14:${PORTSDIR}/print/p5-PDFLib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	XML::Handler::AxPoint.3

.include <bsd.port.mk>
