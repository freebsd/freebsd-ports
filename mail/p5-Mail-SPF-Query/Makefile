# New ports collection makefile for:    p5-Mail-SPF-Query
# Date created:                         Fri Jan 16 12:32:39 PST 2004
# Whom:                                 mharo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Mail-SPF-Query
PORTVERSION=	1.999.1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Query Sender Permitted From for an IP,email,helo

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-CIDR-Lite>=0:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-Mail-SPF-[0-9]*

PERL_CONFIGURE=	yes

MAN1=		spfd.1 spfquery.1
MAN3=		Mail::SPF::Query.3

.include <bsd.port.mk>
