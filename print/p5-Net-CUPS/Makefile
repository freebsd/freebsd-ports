# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	Net-CUPS
PORTVERSION=	0.61
PORTREVISION=	4
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Interface to the CUPS API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libcupsimage.so:${PORTSDIR}/print/cups \
		libcupsfilters.so:${PORTSDIR}/print/cups-filters

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
