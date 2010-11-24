# New ports collection makefile for:	p5-Net-Dropbox-API
# Date created:		2010-11-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Dropbox-API
PORTVERSION=	0.9
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A dropbox API interface

RUN_DEPENDS=	p5-Data-Random>=0:${PORTSDIR}/devel/p5-Data-Random \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-Net-OAuth>=0:${PORTSDIR}/net/p5-Net-OAuth \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Net::Dropbox::API.3

.include <bsd.port.mk>
