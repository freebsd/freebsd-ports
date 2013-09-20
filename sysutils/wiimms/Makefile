# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	wiimms
DISTVERSION=	2.10a
CATEGORIES=	sysutils
MASTER_SITES=	http://gugus69.free.fr/wiimms/ \
		LOCAL/martymac
DISTNAME=	wit-${DISTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	Wiimms ISO Tools

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=	${WRKDIR}/wiimms-iso-tools
USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
	@${INSTALL_PROGRAM} ${WRKSRC}/wit ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/wwt ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/wdf ${PREFIX}/bin
	@${LN} -sf wdf ${PREFIX}/bin/wdf-cat
	@${LN} -sf wdf ${PREFIX}/bin/wdf-dump
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/share/* ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/load-titles.sh ${DATADIR}

.include <bsd.port.post.mk>
