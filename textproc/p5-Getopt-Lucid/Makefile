# New ports collection makefile for:	p5-Getopt-Lucid
# Date created:		2008-02-14
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Lucid
PORTVERSION=	0.16
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Getopt::Lucid - Clear, readable syntax for command line processing

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Exception/Class/TryCatch.pm:${PORTSDIR}/devel/p5-Exception-Class-TryCatch \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Getopt::Lucid.3

.include <bsd.port.mk>
