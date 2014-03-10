# Created by: Sergey Samoyloff <gonza@techline.ru>
# $FreeBSD$

PORTNAME=	ftrack
PORTVERSION=	3.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ibch.ru/forsite/ports/ \
		http://forsite.ibch.ru/ports/
DISTNAME=	ftr${PORTVERSION:S/.//g}sr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTN Messages tracker

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi

USE_ZIP=	yes
USE_GMAKE=	yes
ALL_TARGET=	ftrack
MAKEFILE=	${WRKSRC}/MakeFiles/FreeBSD/Makefile
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
USES=		perl5

PORTDOCS=	ftrack.faq readme report.err

NO_STAGE=	yes
pre-patch:
	${REINPLACE_CMD} -e "s@-I../../hpp -I../../.. -O3@-Ihpp -I${LOCALBASE}/include ${CFLAGS}@g; \
			s@../../src/@src/@g; \
			s@-L../../../smapi -lsmapibsd@-L${LOCALBASE}/lib -lsmapi@g; \
			s@\$$(CC) \$$(LFLAGS) -o ftrack@\$$(CXX) \$$(LFLAGS) -o ftrack@g; \
			s@-o ftrack \$$(OBJS) -L/usr/local/lib -lsmapi@-o ftrack \$$(OBJS) -L${LOCALBASE}/lib -lsmapi@g" ${WRKSRC}/MakeFiles/FreeBSD/Makefile
	${REINPLACE_CMD} -e "s@ftrack.cfg@${PREFIX}/etc/ftrack/ftrack.cfg@g" ${WRKSRC}/hpp/constant.hpp
.for DIR in MakeFiles/FreeBSD src hpp doc/eng samples/tpl
	for FILE in ${WRKSRC}/${DIR}/*; do \
		${TR} -d '\015' < $${FILE} > $${FILE}.new; \
		${MV} $${FILE}.new $${FILE}; \
	done
.endfor
.for DIR in hpp src
	for FILE in ${WRKSRC}/${DIR}/*; do \
		${MV} $${FILE} `${ECHO} $${FILE} | ${TR} "[:upper:]" "[:lower:]"`; \
	done
.endfor

pre-configure:
	${CP} ${WRKSRC}/MakeFiles/FreeBSD/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftrack ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/ftrack
	${INSTALL_DATA} ${WRKSRC}/samples/node.cfg ${PREFIX}/etc/ftrack/ftrack.cfg-dist
	${INSTALL_DATA} ${WRKSRC}/samples/tpl/* ${PREFIX}/etc/ftrack
.for FILE in alt2koi.tbl koi2alt.tbl
	${INSTALL_DATA} ${WRKSRC}/samples/${FILE} ${PREFIX}/etc/ftrack
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/eng/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
