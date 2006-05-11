# ex:ts=8
# New ports collection makefile for:	angst
# Date created:			Dec 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	angst
PORTVERSION=	0.4b
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/angst:}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An active sniffer

BUILD_DEPENDS=	libnet*<=1.1.0,1:${PORTSDIR}/net/libnet10

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet-config

MAN8=		angst.8
PLIST_FILES=	sbin/angst

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
		s,^CFLAGS,#CFLAGS,g ; \
		s,libnet-config,${LIBNET_CONFIG},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
