# New ports collection makefile for:	bandwidthd
# Date created:				Sun Nov  2
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_ICONV=	YES

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
				${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
