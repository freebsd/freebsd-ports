# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	pads
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/passive/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passively detect network assets

CFLAGS+=	-Wno-return-type
USE_CSTD=	gnu89

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes

MAN8=		pads.8 pads-report.8 pads.conf.8

NO_STAGE=	yes
.include <bsd.port.mk>
