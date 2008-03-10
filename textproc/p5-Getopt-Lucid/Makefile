# New ports collection makefile for:	p5-Getopt-Lucid
# Date created:		2008-02-14
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Lucid
PORTVERSION=	0.17
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Getopt::Lucid - Clear, readable syntax for command line processing

BUILD_DEPENDS+=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Exception-Class>=1.23:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Exception-Class-TryCatch>=1.1:${PORTSDIR}/devel/p5-Exception-Class-TryCatch \
		p5-Storable>=2.16:${PORTSDIR}/devel/p5-Storable \
		p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+

MAN3=		Getopt::Lucid.3

.include <bsd.port.mk>
