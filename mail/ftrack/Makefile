# New ports collection makefile for:    ftrack
# Date created:         Thu Dec 21 14:20:49 MSK 2000
# Whom:                 Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	ftrack
PORTVERSION=	3.01
CATEGORIES=	mail
MASTER_SITES=	http://ufm.kgb.ru/FTrack/ftpdir/3.01/
DISTNAME=	ftr${PORTVERSION:S/.//g}s

MAINTAINER=	gonza@techline.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/libsmapi.a:${PORTSDIR}/mail/smapi

USE_ZIP=	yes
USE_GMAKE=	yes
ALL_TARGET=	ftrack
MAKEFILE=	${WRKSRC}/MakeFiles/FreeBSD/Makefile
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

pre-patch:
	${PERL} -pi -e "s@-I../../hpp -I../../.. -O3@-Ihpp -I${LOCALBASE}/include ${CFLAGS}@g; \
			s@../../src/@src/@g; s@g\+\+@${CC}@g; \
			s@-L../smapi -lsmapibsd@-L${LOCALBASE}/lib -lsmapi@g" ${WRKSRC}/MakeFiles/FreeBSD/Makefile
.for DIR in MakeFiles/FreeBSD src hpp doc/eng samples/tpl
	${PERL} -pi -e 's!\r!!' ${WRKSRC}/${DIR}/*
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
