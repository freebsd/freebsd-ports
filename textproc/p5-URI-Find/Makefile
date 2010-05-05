# New ports collection makefile for:	p5-URI-Find
# Date created:				13 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	URI-Find
PORTVERSION=	20100504
CATEGORIES=	textproc net perl5
MASTER_SITES=	CPAN/../../authors/id/M/MS/MSCHWERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to find URIs in arbitrary text

RUN_DEPENDS=	p5-URI>=1.00:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN1=	urifind.1
MAN3=	URI::Find.3 \
	URI::Find::Schemeless.3

.include <bsd.port.mk>
