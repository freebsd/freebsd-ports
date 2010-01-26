# New ports collection makefile for:	p5-Net-GrowlClient
# Date created:		2007-11-22
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Net-GrowlClient
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Perl implementation of Growl Network Notification Protocol

BUILD_DEPENDS=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA

PERL_CONFIGURE=	yes

MAN3=		Net::GrowlClient.3

.include <bsd.port.mk>
