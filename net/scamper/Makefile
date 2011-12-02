# New ports collection makefile for:  scamper
# Date created:        18 Mey 2005
# Whom:                dikshie
#
# $FreeBSD$
#

PORTNAME=	scamper
PORTVERSION=	20111202
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.wand.net.nz/scamper/
DISTNAME=	${PORTNAME}-cvs-${PORTVERSION}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

MAN1=		scamper.1 sc_ally.1 sc_analysis_dump.1 sc_attach.1 \
		sc_tracediff.1 sc_warts2pcap.1 sc_warts2text.1 \
		sc_wartscat.1 sc_wartsdump.1
MAN3=		libscamperfile.3
MAN5=		warts.5

.include <bsd.port.mk>
