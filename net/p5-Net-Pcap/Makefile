# New ports collection makefile for:	Net-Pcap
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-Pcap
PORTVERSION=	0.16
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Interface to pcap(3) LBL packet capture library

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface

PERL_CONFIGURE=	yes

MAN1=		pcapinfo.1
MAN3=		Net::Pcap.3

.include <bsd.port.mk>
