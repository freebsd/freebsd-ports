# New ports collection makefile for:	Net-IMAP-Client
# Date created:	   02 Feb 2010
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-IMAP-Client
PORTVERSION=	0.93
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Not so simple IMAP client library

RUN_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL

PERL_CONFIGURE=	YES

MAN3=		Net::IMAP::Client.3 Net::IMAP::Client::MsgAddress.3 \
		Net::IMAP::Client::MsgSummary.3

.include <bsd.port.mk>
