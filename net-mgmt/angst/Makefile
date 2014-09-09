# Created by: ijliao
# $FreeBSD$

PORTNAME=	angst
PORTVERSION=	0.4b
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/${PORTNAME}-0.4.tar.gz \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/angst:}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Active sniffer

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

PLIST_FILES=	man/man8/angst.8.gz sbin/angst

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -Ee \
		's,^(CC|CFLAGS).*,#&,; \
		 s,libnet-config,${LIBNET_CONFIG},; \
		 s,--defines,& --cflags,' \
		 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
