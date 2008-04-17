# New ports collection makefile for:   p5-Net-SAP
# Date created:                                Jul 25 2004
# Whom:                                Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SAP
PORTVERSION=	0.10
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Session Announcement Protocol (rfc2974) packet parser

RUN_DEPENDS=	${SITE_PERL}/Net/SDP.pm:${PORTSDIR}/net/p5-Net-SDP \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	YES

MAN1=		psapd.1
MAN3=		Net::SAP.3 Net::SAP::Packet.3

.include <bsd.port.mk>
