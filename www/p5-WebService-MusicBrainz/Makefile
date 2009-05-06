# New ports collection makefile for:	p5-WebService-MusicBrainz
# Date created:		2009-01-19
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	WebService-MusicBrainz
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cjk32@cam.ac.uk
COMMENT=	Perl interface to MusicBrainz

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WebService::MusicBrainz.3 \
		WebService::MusicBrainz::Artist.3 \
		WebService::MusicBrainz::Label.3 \
		WebService::MusicBrainz::Query.3 \
		WebService::MusicBrainz::Release.3 \
		WebService::MusicBrainz::Response.3 \
		WebService::MusicBrainz::Track.3 \
		WebService::MusicBrainz::Response::Alias.3 \
		WebService::MusicBrainz::Response::AliasList.3 \
		WebService::MusicBrainz::Response::Artist.3 \
		WebService::MusicBrainz::Response::ArtistList.3 \
		WebService::MusicBrainz::Response::Disc.3 \
		WebService::MusicBrainz::Response::DiscList.3 \
		WebService::MusicBrainz::Response::Label.3 \
		WebService::MusicBrainz::Response::LabelList.3 \
		WebService::MusicBrainz::Response::Metadata.3 \
		WebService::MusicBrainz::Response::Puid.3 \
		WebService::MusicBrainz::Response::PuidList.3 \
		WebService::MusicBrainz::Response::Relation.3 \
		WebService::MusicBrainz::Response::RelationList.3 \
		WebService::MusicBrainz::Response::Release.3 \
		WebService::MusicBrainz::Response::ReleaseList.3 \
		WebService::MusicBrainz::Response::ReleaseEvent.3 \
		WebService::MusicBrainz::Response::ReleaseEventList.3 \
		WebService::MusicBrainz::Response::Tag.3 \
		WebService::MusicBrainz::Response::TagList.3 \
		WebService::MusicBrainz::Response::Track.3 \
		WebService::MusicBrainz::Response::TrackList.3

.include <bsd.port.mk>
