# Created by: chinsan
# $FreeBSD$

PORTNAME=	Authen-PluggableCaptcha
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pluggable Captcha framework for Perl

BUILD_DEPENDS=	p5-Number-Spell>=0:${PORTSDIR}/textproc/p5-Number-Spell \
		p5-HTML-Email-Obfuscate>=0:${PORTSDIR}/security/p5-HTML-Email-Obfuscate
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Authen::PluggableCaptcha.3 \
		Authen::PluggableCaptcha::Challenge.3 \
		Authen::PluggableCaptcha::Challenge::DoMath.3 \
		Authen::PluggableCaptcha::Challenge::TypeString.3 \
		Authen::PluggableCaptcha::ErrorLoggingObject.3 \
		Authen::PluggableCaptcha::Helpers.3 \
		Authen::PluggableCaptcha::KeyManager.3 \
		Authen::PluggableCaptcha::Render.3 \
		Authen::PluggableCaptcha::Render::Image::Imager.3 \
		Authen::PluggableCaptcha::Render::Image::Imager::effects.3 \
		Authen::PluggableCaptcha::Render::Image::Imager::effects::sinewarp.3 \
		Authen::PluggableCaptcha::Render::Image::Imager::layers.3 \
		Authen::PluggableCaptcha::Render::Text::HTML.3 \
		Authen::PluggableCaptcha::Render::Text::Plain.3 \
		Authen::PluggableCaptcha::StandardAttributesObject.3 \
		Authen::PluggableCaptcha::Tutorial.3 \
		Authen::PluggableCaptcha::ValidityObject.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
