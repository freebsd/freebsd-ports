# New ports collection makefile for:    ftrack
# Date created:         Thu Dec 21 14:20:49 MSK 2000
# Whom:                 Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	ftrack
PORTVERSION=	3.01
PORTREVISION=	2
CATEGORIES=	mail
# mastersite disappeared in August 2003
MASTER_SITES=	# http://gonza.bizhost.ru/ports/
DISTNAME=	ftr${PORTVERSION:S/.//g}s

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTN Messages tracker

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi

USE_ZIP=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	ftrack
MAKEFILE=	${WRKSRC}/MakeFiles/FreeBSD/Makefile
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

pre-patch:
	${REINPLACE_CMD} -e "s@-I../../hpp -I../../.. -O3@-Ihpp -I${LOCALBASE}/include ${CFLAGS}@g; \
			s@../../src/@src/@g; s@g\+\+@${CC}@g; \
			s@-L../smapi -lsmapibsd@-L${LOCALBASE}/lib -lsmapi@g" ${WRKSRC}/MakeFiles/FreeBSD/Makefile
.for DIR in MakeFiles/FreeBSD src hpp doc/eng samples/tpl
	for FILE in ${WRKSRC}/${DIR}/*; do \
		${TR} -d '\015' < $${FILE} > $${FILE}.new; \
		${MV} $${FILE}.new $${FILE}; \
	done
.endfor

pre-configure:
	${CP} ${WRKSRC}/MakeFiles/FreeBSD/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftrack ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/etc/ftrack
	${INSTALL_DATA} ${WRKSRC}/samples/node.cfg ${PREFIX}/etc/ftrack/ftrack.cfg-dist
	${MKDIR} ${PREFIX}/share/doc/ftrack
	${INSTALL_DATA} ${WRKSRC}/doc/eng/* ${PREFIX}/share/doc/ftrack
	${INSTALL_DATA} ${WRKSRC}/samples/tpl/* ${PREFIX}/etc/ftrack
.for FILE in alt2koi.tbl koi2alt.tbl
	${INSTALL_DATA} ${WRKSRC}/samples/${FILE} ${PREFIX}/etc/ftrack
.endfor

.include <bsd.port.mk>
