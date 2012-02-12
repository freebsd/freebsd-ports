# New ports collection makefile for:	p5-Net-GitHub
# Date created:		                2009-04-21
# Whom:			                Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-GitHub
DISTVERSION=	0.40_04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FAYLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to github.com

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Tree>0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-WWW-Mechanize-GZip>0:${PORTSDIR}/www/p5-WWW-Mechanize-GZip \
		p5-JSON-Any>0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-LWP-Protocol-https>0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-JSON-XS>0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Crypt-SSLeay>0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Test-MockModule>0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::GitHub.3 \
		Net::GitHub::V2.3 \
		Net::GitHub::V2::Commits.3 \
		Net::GitHub::V2::HasRepo.3 \
		Net::GitHub::V2::Issues.3 \
		Net::GitHub::V2::Network.3 \
		Net::GitHub::V2::NoRepo.3 \
		Net::GitHub::V2::Object.3 \
		Net::GitHub::V2::Organizations.3 \
		Net::GitHub::V2::PullRequest.3 \
		Net::GitHub::V2::Repositories.3 \
		Net::GitHub::V2::Users.3 \
		Net::GitHub::V3.3 \
		Net::GitHub::V3::Gists.3 \
		Net::GitHub::V3::GitData.3 \
		Net::GitHub::V3::Issues.3 \
		Net::GitHub::V3::Orgs.3 \
		Net::GitHub::V3::PullRequests.3 \
		Net::GitHub::V3::Query.3 \
		Net::GitHub::V3::Repos.3 \
		Net::GitHub::V3::Users.3

.include <bsd.port.mk>
