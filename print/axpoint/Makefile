# ex:ts=8
# Ports collection makefile for:	axpoint
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axpoint
PORTVERSION=	1.30
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
DISTNAME=	XML-Handler-AxPoint-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Based Presentations

BUILD_DEPENDS=	${PERL_SITELIBDIR}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${PERL_SITELIBDIR}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		${PERL_SITELIBDIR}/PDFLib.pm:${PORTSDIR}/print/p5-PDFLib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_SITELIBDIR=	${SITE_PERL}
USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	XML::Handler::AxPoint.3

.include <bsd.port.mk>
