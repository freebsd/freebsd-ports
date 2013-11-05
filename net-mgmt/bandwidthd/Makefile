# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LICENSE=	GPLv2

LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd

USE_CSTD=	gnu89

GNU_CONFIGURE=	YES
USES=		iconv gmake

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
	    ${STAGEDIR}${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
