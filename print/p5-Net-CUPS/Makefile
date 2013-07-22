# New ports collection makefile for:	p5-Net-CUPS
# Date created:		2011-09-11
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-CUPS
PORTVERSION=	0.61
PORTREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Interface to the CUPS API

BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-client
LIB_DEPENDS=	cupsimage.2:${PORTSDIR}/print/cups-image

PERL_CONFIGURE=	yes

MAN3=		Net::CUPS.3 \
		Net::CUPS::Destination.3 \
		Net::CUPS::IPP.3 \
		Net::CUPS::PPD.3

.include <bsd.port.mk>
