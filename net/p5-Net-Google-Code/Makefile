# New ports collection makefile for:	p5-Net-Google-Code
# Date created:				2010-08-26
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-Code
PORTVERSION=	0.19
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Simple client library for Google code

BUILD_DEPENDS=	${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/Test/MockModule.pm:${PORTSDIR}/devel/p5-Test-MockModule \
		${SITE_PERL}/Test/Mock/LWP.pm:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Mock/LWP.pm:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		${SITE_PERL}/Test/MockModule.pm:${PORTSDIR}/devel/p5-Test-MockModule \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Any/Moose.pm:${PORTSDIR}/devel/p5-Any-Moose \
		${SITE_PERL}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/JSON.pm:${PORTSDIR}/converters/p5-JSON \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/WWW/Mechanize/Link.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/XML/FeedPP.pm:${PORTSDIR}/textproc/p5-XML-FeedPP

PERL_CONFIGURE=	yes

MAN3=		Net::Google::Code.3 \
		Net::Google::Code::AtomParser.3 \
		Net::Google::Code::DateTime.3 \
		Net::Google::Code::Download.3 \
		Net::Google::Code::Issue.3 \
		Net::Google::Code::Issue::Attachment.3 \
		Net::Google::Code::Issue::Base.3 \
		Net::Google::Code::Issue::Comment.3 \
		Net::Google::Code::Issue::Search.3 \
		Net::Google::Code::Issue::Util.3 \
		Net::Google::Code::Role::Authentication.3 \
		Net::Google::Code::Role::Fetchable.3 \
		Net::Google::Code::Role::HTMLTree.3 \
		Net::Google::Code::Role::Pageable.3 \
		Net::Google::Code::Role::Predefined.3 \
		Net::Google::Code::Role::URL.3 \
		Net::Google::Code::TypicalRoles.3 \
		Net::Google::Code::Wiki.3 \
		Net::Google::Code::Wiki::Comment.3

.include <bsd.port.mk>
