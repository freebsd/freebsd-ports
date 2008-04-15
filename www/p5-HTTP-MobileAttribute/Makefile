# New ports collection makefile for:	p5-HTTP-MobileAttribute
# Date created:	Fri Apr 11 16:32:54 2008
# Whom:	Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-MobileAttribute
PORTVERSION=	0.11.1
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/T/TO/TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	cherry@trombik.org
COMMENT=	Yet Another HTTP::MobileAgent

BUILD_DEPENDS=	p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn
RUN_DEPENDS=	p5-Class-Component>=0.15:${PORTSDIR}/devel/p5-Class-Component

MAN3=	HTTP::MobileAttribute::Plugin::Encoding.3 \
	HTTP::MobileAttribute::Plugin::IS::DoCoMo.3 \
	HTTP::MobileAttribute::Plugin::CarrierLetter.3 \
	HTTP::MobileAttribute::Plugin::CIDR.3 \
	HTTP::MobileAttribute::Attribute::CarrierMethod.3 \
	HTTP::MobileAttribute::CarrierDetector.3 \
	HTTP::MobileAttribute::Plugin::IS.3 \
	HTTP::MobileAttribute::Plugin::UserID.3 \
	HTTP::MobileAttribute::Plugin::XHTMLCompliant.3 \
	HTTP::MobileAttribute.3 \
	HTTP::MobileAttribute::Plugin::IS::ThirdForce.3 \
	HTTP::MobileAttribute::Plugin::IS::EZweb.3 \
	HTTP::MobileAttribute::Agent::Base.3 \
	HTTP::MobileAttribute::Plugin::Display.3

PERL_CONFIGURE=	Yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
