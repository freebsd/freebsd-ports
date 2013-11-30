# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Jifty-Plugin-OpenID
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Provides OpenID authentication for your Jifty App

BUILD_DEPENDS=	p5-Jifty>=0:${PORTSDIR}/www/p5-Jifty \
		p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Net-OpenID-Consumer>=0:${PORTSDIR}/net/p5-Net-OpenID-Consumer \
		p5-LWPx-ParanoidAgent>=0:${PORTSDIR}/www/p5-LWPx-ParanoidAgent
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		does not build

USES=		perl5
USE_PERL5=	configure

MAN3=		Jifty::Plugin::OpenID::View.3 \
		Jifty::Plugin::OpenID.3 \
		Jifty::Plugin::OpenID::Action::VerifyOpenID.3 \
		Jifty::Plugin::OpenID::Action::AuthenticateOpenID.3 \
		Jifty::Plugin::OpenID::Mixin::Model::User.3 \
		Jifty::Plugin::OpenID::Action::CreateOpenIDUser.3 \
		Jifty::Plugin::OpenID::Dispatcher.3

NO_STAGE=	yes
.include <bsd.port.mk>
