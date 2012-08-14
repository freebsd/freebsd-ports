# New ports collection makefile for:	Net::APNS
# Date created:		14 Aug 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-APNS
PORTVERSION=	0.0202
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Apple Push Notification Service

RUN_DEPENDS=	\
	p5-Any-Moose>=0.10:${PORTSDIR}/devel/p5-Any-Moose \
	p5-JSON-XS>=2.25:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Net-SSLeay>=1.35:${PORTSDIR}/security/p5-Net-SSLeay \
	p5-Sub-Exporter>=0.982:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::APNS.3 \
	Net::APNS::Notification.3

.include <bsd.port.mk>
