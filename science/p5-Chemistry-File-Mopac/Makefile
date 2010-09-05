# New ports collection makefile for:	p5-Chemistry-File-Mopac
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-Mopac
PORTVERSION=	0.15
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	MOPAC 6 input file reader/writer

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/InternalCoords.pm:${PORTSDIR}/science/p5-Chemistry-InternalCoords
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/InternalCoords.pm:${PORTSDIR}/science/p5-Chemistry-InternalCoords

MAN3=	Chemistry::File::Mopac.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
