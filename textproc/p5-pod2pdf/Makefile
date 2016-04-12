# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pod2pdf
PORTVERSION=	0.42
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JONALLEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Converts POD to PDF format

RUN_DEPENDS=	p5-PDF-API2>=0.60:textproc/p5-PDF-API2 \
		p5-Pod-Escapes>0:textproc/p5-Pod-Escapes \
		p5-Getopt-ArgvFile>0:devel/p5-Getopt-ArgvFile
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
