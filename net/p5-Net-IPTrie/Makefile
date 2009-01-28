# New ports collection makefile for:	Net-IPTrie
# Date created: 			13 December 2007
# Whom:					Matthew Luckie <mjl@luckie.org.nz>
#
# $FreeBSD$
#

PORTNAME=	Net-IPTrie
PORTVERSION=	0.4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Module for building IPv4 and IPv6 address space hierarchies

BUILD_DEPENDS=	p5-NetAddr-IP>=4.00.7:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		Net::IPTrie.3 Net::IPTrie::Node.3

.include <bsd.port.mk>
