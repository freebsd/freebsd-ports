# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	szap_s2
PORTVERSION=	20100129s
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nox/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Simple zapping tool for the Linux DVB S2 API

BUILD_DEPENDS=  ${LOCALBASE}/include/linux/dvb/frontend.h:${PORTSDIR}/multimedia/v4l_compat

USES=		gmake tar:bzip2
PATCH_STRIP=	-p1
USE_CSTD=	gnu89
MAKE_ARGS=	INCLUDE=-I"${LOCALBASE}/include"
MAKE_ARGS+=	CC=${CC}
MAKE_ARGS+=	CXX=${CXX}
WRKSRC=		${WRKDIR}/szap-s2-e34f73b254db
PORTDOCS=	README
PLIST_FILES=	bin/szap-s2

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} szap-s2 ${STAGEDIR}/${PREFIX}/bin)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
