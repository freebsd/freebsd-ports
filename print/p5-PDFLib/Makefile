# ex:ts=8
# Ports collection makefile for:	p5-PDFLib
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	PDFLib
PORTVERSION=	0.12
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MS/MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/pdflib_pl.pm:${PORTSDIR}/print/pdflib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes
NO_BUILD=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	PDFLib.3

.include <bsd.port.mk>
