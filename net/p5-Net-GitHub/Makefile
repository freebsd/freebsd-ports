# New ports collection makefile for:	p5-Net-GitHub
# Date created:		                2009-04-21
# Whom:			                Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-GitHub
PORTVERSION=	0.18
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to github.com

RUN_DEPENDS=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/WWW/Mechanize/GZip.pm:${PORTSDIR}/www/p5-WWW-Mechanize-GZip \
		${SITE_PERL}/JSON/Any.pm:${PORTSDIR}/converters/p5-JSON-Any \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Crypt-SSLeay>0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::GitHub.3 Net::GitHub::V1.3 \
		Net::GitHub::V1::Project.3 \
		Net::GitHub::V1::Project::Downloads.3 \
		Net::GitHub::V1::Project::Info.3 \
		Net::GitHub::V1::Project::Role.3 \
		Net::GitHub::V1::Project::Source.3 \
		Net::GitHub::V1::Project::Wiki.3 \
		Net::GitHub::V1::Role.3 \
		Net::GitHub::V1::Search.3 \
		Net::GitHub::V1::User.3 \
		Net::GitHub::V2.3 Net::GitHub::V2::Commits.3 \
		Net::GitHub::V2::HasRepo.3 \
		Net::GitHub::V2::Issues.3 \
		Net::GitHub::V2::Network.3 \
		Net::GitHub::V2::NoRepo.3 \
		Net::GitHub::V2::Object.3 \
		Net::GitHub::V2::Repositories.3 \
		Net::GitHub::V2::Users.3

.include <bsd.port.mk>
