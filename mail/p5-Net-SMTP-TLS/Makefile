# New ports collection makefile for:	p5-Net-SMTP-TLS
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SMTP-TLS
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	An SMTP client supporting TLS and AUTH

RUN_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay

PERL_CONFIGURE=	yes

MAN3=		Net::SMTP::TLS.3

.include <bsd.port.mk>
