# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Facebook-API
PORTVERSION=	0.4.18
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Facebook API implementation in Perl

RUN_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww 

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Facebook::API.3 \
		WWW::Facebook::API::Admin.3 \
		WWW::Facebook::API::Application.3 \
		WWW::Facebook::API::Auth.3 \
		WWW::Facebook::API::Canvas.3 \
		WWW::Facebook::API::Comments.3 \
		WWW::Facebook::API::Connect.3 \
		WWW::Facebook::API::Data.3 \
		WWW::Facebook::API::Events.3 \
		WWW::Facebook::API::Exception.3 \
		WWW::Facebook::API::FBML.3 \
		WWW::Facebook::API::FQL.3 \
		WWW::Facebook::API::Feed.3 \
		WWW::Facebook::API::Friends.3 \
		WWW::Facebook::API::Groups.3 \
		WWW::Facebook::API::Intl.3 \
		WWW::Facebook::API::Links.3 \
		WWW::Facebook::API::LiveMessage.3 \
		WWW::Facebook::API::Message.3 \
		WWW::Facebook::API::Notes.3 \
		WWW::Facebook::API::Notifications.3 \
		WWW::Facebook::API::Pages.3 \
		WWW::Facebook::API::Permissions.3 \
		WWW::Facebook::API::Photos.3 \
		WWW::Facebook::API::Profile.3 \
		WWW::Facebook::API::SMS.3 \
		WWW::Facebook::API::Status.3 \
		WWW::Facebook::API::Stream.3 \
		WWW::Facebook::API::Users.3 \
		WWW::Facebook::API::Video.3

.include <bsd.port.mk>
