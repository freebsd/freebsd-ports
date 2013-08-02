# Created by: clsung
# $FreeBSD$

PORTNAME=	Net-GitHub
DISTVERSION=	0.52
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FAYLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to github.com

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Message>0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize-GZip>=0:${PORTSDIR}/www/p5-WWW-Mechanize-GZip
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::GitHub.3 \
		Net::GitHub::V3.3 \
		Net::GitHub::V3::Events.3 \
		Net::GitHub::V3::Gists.3 \
		Net::GitHub::V3::GitData.3 \
		Net::GitHub::V3::Issues.3 \
		Net::GitHub::V3::OAuth.3 \
		Net::GitHub::V3::Orgs.3 \
		Net::GitHub::V3::PullRequests.3 \
		Net::GitHub::V3::Query.3 \
		Net::GitHub::V3::Repos.3 \
		Net::GitHub::V3::Search.3 \
		Net::GitHub::V3::Users.3

.include <bsd.port.mk>
