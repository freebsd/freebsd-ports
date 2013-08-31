# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdca
PORTVERSION=	0.0.5
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free DTS Coherent Acoustics decoder

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		pkgconfig pathfix
USE_LDCONFIG=	yes

MAN1=		dcadec.1 extract_dca.1
MLINKS=		dcadec.1 dtsdec.1 extract_dca.1 extract_dts.1

.include <bsd.port.mk>
