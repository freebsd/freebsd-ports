# New ports collection makefile for:	XML::Generator::PerlData
# Date created:   31.7.2003
# Whom:           Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	XML-Generator-PerlData
PORTVERSION=	0.89
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
#MASTER_SITE_SUBDIR=	XML
MASTER_SITE_SUBDIR=	../by-authors/id/K/KH/KHAMPTON
PKGNAMEPREFIX=	p5-

MAINTAINER=	hansjoerg.pehofer@uibk.ac.at
COMMENT=	"Perl extension for generating SAX2 events from Perl data structures."

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX/Base.pm:${PORTSDIR}/textproc/p5-XML-SAX-Base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Generator::PerlData.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
