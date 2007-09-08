# ex:ts=8
# Ports collection makefile for:	p5-PDFLib
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	PDFLib
PORTVERSION=	0.14
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MS/MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	More OO interface to pdflib_pl.pm

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/pdflib_pl.pm:${PORTSDIR}/print/pdflib-perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
NO_BUILD=	yes

MAN3=	PDFLib.3

.include <bsd.port.mk>
