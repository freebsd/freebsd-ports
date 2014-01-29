# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	sjitter
PORTVERSION=	0.18.1b
CATEGORIES=	net-mgmt net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.18.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Client/server jitter measurement utility

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	sbin/sjitters sbin/sjitterc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sjitters ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sjitterc ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
