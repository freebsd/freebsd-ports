# New ports collection makefile for:	p5-URI-Find
# Date created:				13 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	URI-Find
PORTVERSION=	20090319
CATEGORIES=	textproc net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to find URIs in arbitrary text

RUN_DEPENDS=	p5-URI>=1.00:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Simple>=0.82:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes

MAN3=	URI::Find.3 \
	URI::Find::Schemeless.3

.include <bsd.port.mk>
