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
DISTNAME=	XML-Handler-AxPoint-${PORTVERSION:S/0$//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Based Presentations

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		p5-Time-Piece>=1.08:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/XML/Filter/XSLT.pm:${PORTSDIR}/textproc/p5-XML-Filter-XSLT \
		p5-XML-SAX>=0.09:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0.39:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-PDFLib>=0.14:${PORTSDIR}/print/p5-PDFLib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Handler::AxPoint.3

.include <bsd.port.mk>
