# New ports collection makefile for:	proggy_fonts
# Date Created:				30 July 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	proggy_fonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.proggyfonts.com/download/
DISTFILES=	ProggyClean.pcf.gz ProggySquare.pcf.gz	\
		ProggySmall.pcf.gz ProggyTiny.pcf.gz	\
		ProggyCleanSZ.pcf.gz ProggySquareSZ.pcf.gz	\
		ProggyTinySZ.pcf.gz ProggyCleanSZBP.pcf.gz	\
		ProggyCleanCP.pcf.zip

MAINTAINER=	llwang@infor.org
COMMENT=	The perfect monospaced bitmap programming fonts

RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
XFONTDIR=	${PREFIX}/lib/X11/fonts/local
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}

post-extract:
	@(cd ${WRKDIR}; for i in *.zip; do ${UNZIP_CMD} $$i; done)

do-install:
	@${MKDIR} ${XFONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/*.pcf.gz ${XFONTDIR}
	@(cd ${XFONTDIR}; mkfontdir)

.include <bsd.port.mk>
