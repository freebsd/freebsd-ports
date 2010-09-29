# New ports collection makefile for:	p5-HTTP-MobileAttribute
# Date created:	Fri Apr 11 16:32:54 2008
# Whom:	Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-MobileAttribute
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Yet Another HTTP::MobileAgent

RUN_DEPENDS=	p5-Class-Component>=0.17:${PORTSDIR}/devel/p5-Class-Component \
		p5-UNIVERSAL-require>=0.13:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	Yes

MAN3=		HTTP::MobileAttribute.3 \
		HTTP::MobileAttribute::Agent::Base.3 \
		HTTP::MobileAttribute::Attribute::CarrierMethod.3 \
		HTTP::MobileAttribute::CarrierDetector.3 \
		HTTP::MobileAttribute::Plugin::CIDR.3 \
		HTTP::MobileAttribute::Plugin::CarrierLetter.3 \
		HTTP::MobileAttribute::Plugin::Display.3 \
		HTTP::MobileAttribute::Plugin::DoCoMo::Browser.3 \
		HTTP::MobileAttribute::Plugin::Encoding.3 \
		HTTP::MobileAttribute::Plugin::GPS.3 \
		HTTP::MobileAttribute::Plugin::IS.3 \
		HTTP::MobileAttribute::Plugin::IS::DoCoMo.3 \
		HTTP::MobileAttribute::Plugin::IS::EZweb.3 \
		HTTP::MobileAttribute::Plugin::IS::ThirdForce.3 \
		HTTP::MobileAttribute::Plugin::Locator.3 \
		HTTP::MobileAttribute::Plugin::UserID.3 \
		HTTP::MobileAttribute::Plugin::XHTMLCompliant.3

.include <bsd.port.mk>
