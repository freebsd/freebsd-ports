# Ports collection makefile for:  sing
# Date created:			  Oct 6 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	sing
PORTVERSION=	1.0
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	SING-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes
MAN8=		sing.8

post-extract:
	@${RM} -rf ${WRKSRC}/libpcap*

.include <bsd.port.mk>
