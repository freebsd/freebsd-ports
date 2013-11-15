# Created by: mharo@FreeBSD.org
# $FreeBSD$

PORTNAME=	Mail-SPF-Query
PORTVERSION=	1.999.1
PORTREVISION=	1
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

DEPRECATED=	Use mail/p5-Mail-SPF instead
EXPIRATION_DATE=2013-12-31

CONFLICTS_INSTALL=	libspf2-[0-9]* p5-Mail-SPF-[0-9]*

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
