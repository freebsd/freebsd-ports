# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aspcud
PORTVERSION=	1.8.0
DISTVERSIONSUFFIX=	-source
CATEGORIES=	math ports-mgmt sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Advanced solver for package dependencies

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	gringo:${PORTSDIR}/math/gringo \
				clasp:${PORTSDIR}/math/clasp \
				bash:${PORTSDIR}/shells/bash

USE_PYTHON_RUN=	yes
USES=	cmake:outsource shebangfix
SHEBANG_FILES=	${WRKSRC}/scripts/aspcud.sh

post-patch:
	${REINPLACE_CMD} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/scripts/${PORTNAME}.sh

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/cudf2lp ${STAGEDIR}${PREFIX}/bin/cudf2lp
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/encodings/misc2012.lp ${STAGEDIR}${DATADIR}/misc2012.lp
	${INSTALL_DATA} ${WRKSRC}/scripts/encodings/specification.lp ${STAGEDIR}${DATADIR}/specification.lp

.include <bsd.port.mk>
