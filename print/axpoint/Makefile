# ex:ts=8
# Ports collection makefile for:	axpoint
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axpoint
PORTVERSION=	1.21
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
DISTNAME=	XML-Handler-AxPoint-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	XML Based Presentations

BUILD_DEPENDS=	${PERL_SITELIBDIR}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${PERL_SITELIBDIR}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		${PERL_SITELIBDIR}/PDFLib.pm:${PORTSDIR}/print/p5-PDFLib
LIB_DEPENDS=	pdf.4:${PORTSDIR}/print/pdflib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	XML::Handler::AxPoint.3

.include <bsd.port.mk>
