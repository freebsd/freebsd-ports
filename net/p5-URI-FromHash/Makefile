# New ports collection makefile for:	p5-URI-FromHash
# Date created:		2 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-FromHash
DISTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Create URI from hash of components

BUILD_DEPENDS=	p5-URI>=1.22:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES

MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
