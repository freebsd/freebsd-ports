# New ports collection makefile for:	p5-Net-Google-AuthSub
# Date created:		2008-02-21
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-AuthSub
PORTVERSION=	0.5
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Interact with sites that implement Google style AuthSub

RUN_DEPENDS=	p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Net::Google::AuthSub::Response.3 \
		Net::Google::AuthSub.3

.include <bsd.port.mk>
