# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	szap_s2
PORTVERSION=	20100129s
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple zapping tool for the Linux DVB S2 API

LICENSE=	GPLv2+

BUILD_DEPENDS=  ${LOCALBASE}/include/linux/dvb/frontend.h:multimedia/v4l_compat

USES=		gmake tar:bzip2
USE_CSTD=	gnu89
MAKE_ARGS=	INCLUDE=-I"${LOCALBASE}/include" \
		CC="${CC}" \
		CXX="${CXX}"
WRKSRC=		${WRKDIR}/szap-s2-e34f73b254db

PORTDOCS=	README
PLIST_FILES=	bin/szap-s2

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/szap-s2 ${STAGEDIR}/${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
