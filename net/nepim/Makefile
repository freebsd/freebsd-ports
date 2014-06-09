# Created by: Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	nepim
PORTVERSION=	0.53
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	nepim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for measuring available bandwidth between hosts

LIB_DEPENDS=	liboop.so:${PORTSDIR}/devel/liboop

USES=		gmake
ALL_TARGET=	default
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CFLAGS+=	-DHAVE_IP_MREQ -DHAVE_IPV6_MREQ -DHAVE_IP_MREQN \
		-DHAVE_GROUP_SOURCE_REQ

PLIST_FILES=	bin/nepim

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nepim ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
