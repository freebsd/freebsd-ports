# New ports collection makefile for:	bandwidthd
# Date created:				Sun Nov  2
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	bandwidthd
PORTVERSION=	1.1.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Tracks bandwidth usage by IP address

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

USE_GMAKE=	YES
USE_REINPLACE=	YES
CFLAGS+=	-DFREEBSD -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's!localtime(!localtime((time_t *)!' ${WRKSRC}/graph.c

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
				${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
