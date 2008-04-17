# New ports collection makefile for:	p5-Net-Address-IPv4-Local
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Address-IPv4-Local
PORTVERSION=	0.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A class for discovering the local system's IP address

BUILD_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Net::Address::IPv4::Local.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
