# New ports collection makefile for: p5-Net-Delicious
# Date created: August 03, 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Delicious
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OOP for managing posts on del.icio.us

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-YAML>=0.35:${PORTSDIR}/textproc/p5-YAML \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Log-Dispatch>=2:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Time-HiRes>=1.65:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-IO-stringy>=2.1:${PORTSDIR}/devel/p5-IO-stringy \
		p5-PathTools>=0.8:${PORTSDIR}/devel/p5-PathTools \
		p5-TimeDate>=2.27:${PORTSDIR}/devel/p5-TimeDate \
		p5-Config-Simple>=2:${PORTSDIR}/devel/p5-Config-Simple \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

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

.include <bsd.port.mk>
