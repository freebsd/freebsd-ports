# New ports collection makefile for:	p5-Net
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net
PORTVERSION=	1.22
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	libnet-${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl5 modules to access and use network protocols

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL

PERL_CONFIGURE=	yes

MAN3=		Net::Cmd.3 \
		Net::Config.3 \
		Net::Domain.3 \
		Net::FTP.3 \
		Net::NNTP.3 \
		Net::Netrc.3 \
		Net::POP3.3 \
		Net::SMTP.3 \
		Net::Time.3 \
		Net::libnetFAQ.3

.include <bsd.port.mk>
