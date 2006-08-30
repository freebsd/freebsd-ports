# New ports collection makefile for:	libdts
# Date created:				12th May 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdts
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://debian.unnet.nl/pub/videolan/libdts/${PORTVERSION}/ \
		http://download.videolan.org/pub/videolan/libdts/${PORTVERSION}/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Free DTS Coherent Acoustics decoder

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnomehack

MAN1=		dtsdec.1 extract_dts.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
post-patch:
	@${REINPLACE_CMD} -e 's|-ldts|-ldts_pic|' ${WRKSRC}/libdts/libdts.pc.in
.endif

.include <bsd.port.post.mk>
