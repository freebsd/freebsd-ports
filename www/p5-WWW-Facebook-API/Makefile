# New ports collection makefile for:	p5-WWW-Facebook-API
# Date created:				2007-08-27
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Facebook-API
PORTVERSION=	0.4.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Facebook API implementation in Perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Readonly.pm:${PORTSDIR}/devel/p5-Readonly \
		${SITE_PERL}/JSON/Any.pm:${PORTSDIR}/converters/p5-JSON-Any \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Facebook::API.3 \
		WWW::Facebook::API::Admin.3 \
		WWW::Facebook::API::Application.3 \
		WWW::Facebook::API::Auth.3 \
		WWW::Facebook::API::Canvas.3 \
		WWW::Facebook::API::Data.3 \
		WWW::Facebook::API::Events.3 \
		WWW::Facebook::API::FBML.3 \
		WWW::Facebook::API::FQL.3 \
		WWW::Facebook::API::Feed.3 \
		WWW::Facebook::API::Friends.3 \
		WWW::Facebook::API::Groups.3 \
		WWW::Facebook::API::Marketplace.3 \
		WWW::Facebook::API::Notifications.3 \
		WWW::Facebook::API::Pages.3 \
		WWW::Facebook::API::Photos.3 \
		WWW::Facebook::API::Profile.3 \
		WWW::Facebook::API::SMS.3 \
		WWW::Facebook::API::Users.3

.include <bsd.port.mk>
