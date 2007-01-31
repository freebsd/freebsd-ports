# ex:ts=8
# New ports collection makefile for:	angst
# Date created:			Dec 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	angst
PORTVERSION=	0.4b
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/angst:}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An active sniffer

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

MAN8=		angst.8
PLIST_FILES=	sbin/angst

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -Ee \
		's,^(CC|CFLAGS).*,#&,; \
		 s,libnet-config,${LIBNET_CONFIG},; \
		 s,--defines,& --cflags,' \
		 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
