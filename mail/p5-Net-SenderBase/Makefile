# New ports collection makefile for:	mail/p5-Net-SenderBase
# Date created:				2009 March 18
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SenderBase
PORTVERSION=	1.01
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd@opal.com
COMMENT=	Query the SenderBase service

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

PERL_CONFIGURE=	yes

MAN3=		Net::SenderBase.3 \
		Net::SenderBase::Query.3 \
		Net::SenderBase::Results.3

.include <bsd.port.mk>
