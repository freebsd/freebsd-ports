# New ports collection makefile for:   p5-Net-SAP
# Date created:                                Jul 25 2004
# Whom:                                Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SAP
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Session Announcement Protocol (rfc2974) packet parser

RUN_DEPENDS=	${SITE_PERL}/Net/SDP.pm:${PORTSDIR}/net/p5-Net-SDP
BUILD_DEPENDS=	${SITE_PERL}/Net/SDP.pm:${PORTSDIR}/net/p5-Net-SDP

PERL_MODBUILD=	YES

MAN1=		psapd.1
MAN3=		Net::SAP.3 Net::SAP::Packet.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
