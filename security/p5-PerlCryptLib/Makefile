# New ports collection makefile for:	p5-PerlCryptLib
# Date created:		2006-08-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	PerlCryptLib
PORTVERSION=	1.10
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/A/AL/ALVAROL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Peter Guttman cryptlib API

LIB_DEPENDS=	cl:${PORTSDIR}/security/cryptlib

PERL_CONFIGURE=	5.8.0+

MAN3=		PerlCryptLib.3

.include <bsd.port.mk>
