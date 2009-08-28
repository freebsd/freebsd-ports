# New ports collection makefile for:	XML-SAXDriver-CSV
# Date created:	   			2006/07/19
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML-SAXDriver-CSV
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl SAX driver for converting CSV files to XML

BUILD_DEPENDS=	p5-Text-CSV_XS>=0.22:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-XML-SAX>=0.14:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_DOS2UNIX=	yes

MAN3=		XML::SAXDriver::CSV.3

.include <bsd.port.mk>
