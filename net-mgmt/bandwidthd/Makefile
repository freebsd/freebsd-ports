# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

USE_CSTD=	gnu89

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USES=		iconv

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
				${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
