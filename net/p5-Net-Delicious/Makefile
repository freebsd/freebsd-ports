# New ports collection makefile for: p5-Net-Delicious
# Date created: August 03, 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Delicious
PORTVERSION=	0.6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ascope@cpan.org
COMMENT=	OOP for managing posts on del.icio.us

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Delicious.3 \
		Net::Delicious::Constants.3 \
		Net::Delicious::Constants::Api.3 \
		Net::Delicious::Constants::Response.3 \
		Net::Delicious::Constants::Uri.3 \
		Net::Delicious::Date.3 \
		Net::Delicious::Iterator.3 \
		Net::Delicious::Post.3 \
		Net::Delicious::Subscription.3 \
		Net::Delicious::Tag.3 \
		Net::Delicious::User.3

.include <bsd.port.mk>
