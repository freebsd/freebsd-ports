# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-ACL
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Class representing a generic access-list/route-map

BUILD_DEPENDS=	p5-Cisco-Reconfig>=0.05:${PORTSDIR}/net-mgmt/p5-Cisco-Reconfig \
		p5-IO-String>=1.02:${PORTSDIR}/devel/p5-IO-String \
		p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Signature>=1.04:${PORTSDIR}/devel/p5-Test-Signature

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::ACL.3 Net::ACL::Bootstrap.3 Net::ACL::File.3 \
		Net::ACL::File::ASPath.3 Net::ACL::File::Community.3 \
		Net::ACL::File::IPAccess.3 Net::ACL::File::IPAccessExt.3 \
		Net::ACL::File::Prefix.3 Net::ACL::File::RouteMap.3 \
		Net::ACL::File::Standard.3 Net::ACL::IPAccessExtRule.3 \
		Net::ACL::Match.3 Net::ACL::Match::IP.3 \
		Net::ACL::Match::List.3 Net::ACL::Match::Member.3 \
		Net::ACL::Match::Prefix.3 Net::ACL::Match::Regexp.3 \
		Net::ACL::Match::Scalar.3 Net::ACL::RouteMapRule.3 \
		Net::ACL::Rule.3 Net::ACL::Set.3 Net::ACL::Set::Add.3 \
		Net::ACL::Set::Scalar.3 Net::ACL::Set::Union.3

NO_STAGE=	yes
.include <bsd.port.mk>
