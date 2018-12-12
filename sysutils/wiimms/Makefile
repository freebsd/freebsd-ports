# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wiimms
DISTVERSION=	2.23a
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://gugus69.free.fr/wiimms/ \
		LOCAL/martymac
DISTNAME=	wit-${DISTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Wiimms ISO Tools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

WRKSRC=	${WRKDIR}/wiimms-iso-tools
USES+=		gmake
USE_GCC=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/*.sh \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/setup/*.sh \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/share/wit|/share/wiimms|g' \
		${WRKSRC}/Makefile

pre-configure:
	@${CHMOD} +x ${WRKSRC}/setup.sh

do-configure:
	@cd ${WRKSRC} && ./setup.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wwt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wdf ${STAGEDIR}${PREFIX}/bin
	${LN} -sf wdf ${STAGEDIR}${PREFIX}/bin/wdf-cat
	${LN} -sf wdf ${STAGEDIR}${PREFIX}/bin/wdf-dump
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/load-titles.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
