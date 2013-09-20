# $FreeBSD$

PORTNAME=	pev
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	The PE analysis toolkit

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
USE_LDCONFIG=	yes

PATCH_STRIP=	-p1

MAN1=	readpe.1 pedis.1 pepack.1 pescan.1 \
	rva2ofs.1 pesec.1 ofs2rva.1 pestr.1 pehash.1

MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
