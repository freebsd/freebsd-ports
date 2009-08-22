# New ports collection makefile for: pads
# Date created: 21 Feburary 2005
# Whom: Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=	pads
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/passive/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passively detect network assets

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes

MAN8=		pads.8 pads-report.8 pads.conf.8

.include <bsd.port.mk>
