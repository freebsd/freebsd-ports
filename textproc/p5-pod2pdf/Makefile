# New ports collection makefile for:	textproc/p5-pod2pdf
# Date created:				02 October 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pod2pdf
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JO/JONALLEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Converts POD to PDF format

RUN_DEPENDS=	p5-PDF-API2>=0.60:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-Pod-Escapes>0:${PORTSDIR}/textproc/p5-Pod-Escapes \
		p5-Getopt-ArgvFile>0:${PORTSDIR}/devel/p5-Getopt-ArgvFile
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2pdf.1

.include <bsd.port.mk>
