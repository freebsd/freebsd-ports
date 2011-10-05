# New ports collection makefile for:	p5-Net-Plurk
# Date created:		2010-07-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Plurk
PORTVERSION=	0.11
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLSUNG
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A perl interface to Plurk API

BUILD_DEPENDS=	p5-AnyEvent-HTTP>=0:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-HTTP-Lite>=0:${PORTSDIR}/www/p5-HTTP-Lite \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Math-Base36>=0:${PORTSDIR}/math/p5-Math-Base36 \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Net-OAuth>=0.27:${PORTSDIR}/net/p5-Net-OAuth \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Plurk.3 \
		Net::Plurk::OAuth.3 \
		Net::Plurk::Plurk.3 \
		Net::Plurk::User.3 \
		Net::Plurk::UserProfile.3

.include <bsd.port.mk>
