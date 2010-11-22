# New ports collection makefile for:	schroedinger
# Date created:		2008-06-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	schroedinger
PORTVERSION=	1.0.10
CATEGORIES=	multimedia
MASTER_SITES=	http://diracvideo.org/download/schroedinger/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	High-speed Dirac codec

LIB_DEPENDS=	orc-0.4:${PORTSDIR}/devel/orc
BUILD_DEPENDS=	orc>=0.4.10:${PORTSDIR}/devel/orc

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^pkgconfigdir=.*|pkgconfigdir="\\$$(prefix)/libdata/pkgconfig"|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
