# New ports collection makefile for:	bandwidthd
# Date created:				Sun Nov  2
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	bandwidthd
PORTVERSION=	1.1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-1.1.7b
EXTRACT_SUFX=	.tgz

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Tracks bandwidth usage by IP address

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd\
		iconv.3:${PORTSDIR}/converters/libiconv

USE_GMAKE=	YES
USE_REINPLACE=	YES

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
				${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
