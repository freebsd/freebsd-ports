# ex:ts=8
# New ports collection makefile for:	angst
# Date created:			Dec 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	angst
PORTVERSION=	0.4b
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/angst:}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	An active sniffer

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet-config

USE_REINPLACE=	yes

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
