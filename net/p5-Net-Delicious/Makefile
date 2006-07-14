# New ports collection makefile for: p5-Net-Delicious
# Date created: August 03, 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Delicious
PORTVERSION=	1.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ascope@cpan.org
COMMENT=	OOP for managing posts on del.icio.us

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Config/Simple.pm:${PORTSDIR}/devel/p5-Config-Simple \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Delicious.3 \
		Net::Delicious::Bundle.3 \
		Net::Delicious::Config.3 \
		Net::Delicious::Constants.3 \
		Net::Delicious::Constants::Config.3 \
		Net::Delicious::Constants::Pause.3 \
		Net::Delicious::Constants::Response.3 \
		Net::Delicious::Constants::Uri.3 \
		Net::Delicious::Date.3 \
		Net::Delicious::Iterator.3 \
		Net::Delicious::Object.3 \
		Net::Delicious::Post.3 \
		Net::Delicious::Subscription.3 \
		Net::Delicious::Tag.3 \
		Net::Delicious::User.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 # inherited from www/p5-libwww
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
