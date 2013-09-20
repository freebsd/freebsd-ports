# Created by: Matthew Luckie <mjl@luckie.org.nz>
# $FreeBSD$

PORTNAME=	Net-IPTrie
PORTVERSION=	0.7
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Module for building IPv4 and IPv6 address space hierarchies

BUILD_DEPENDS=	p5-NetAddr-IP>=4.00.7:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::IPTrie.3 Net::IPTrie::Node.3

NO_STAGE=	yes
.include <bsd.port.mk>
