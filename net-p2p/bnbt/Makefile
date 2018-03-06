# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	bnbt
PORTVERSION=	8.5
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://opensource.depthstrike.com/${PORTNAME}/
DISTNAME=	${SNAPSHOT}-${PORTNAME}${PORTVERSION:C/\.//}-src
SNAPSHOT=	20060727

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ BitTorrent Tracker

OPTIONS_DEFINE=	MYSQL DOCS

USES=		dos2unix gmake tar:bzip2

SUB_FILES=	pkg-message
USE_RC_SUBR=	bnbt

PORTDOCS=	footer.html header.html

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
ALL_TARGET=	bnbtmysql
USE_MYSQL=	yes
.else
ALL_TARGET=	bnbt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS} -I${PREFIX}/include| ; \
		s|LFLAGS =|LFLAGS = -L${PREFIX}/lib/mysql| ;  \
		s|g++|${CXX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|\([a-z]*\.bnbt\)|${PREFIX}/etc/${PORTNAME}/\1|' \
		${WRKSRC}/config.cpp
	@${REINPLACE_CMD} -e 's|bnbt.cfg|${PREFIX}/etc/${PORTNAME}/bnbt.cfg|' \
		${WRKSRC}/config.h ${WRKSRC}/config.cpp ${WRKSRC}/tracker.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ALL_TARGET} ${STAGEDIR}${PREFIX}/bin/bnbt
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${TOUCH} ${STAGEDIR}/var/log/${PORTNAME}/.keep
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${TOUCH} ${STAGEDIR}${ETCDIR}/.keep

.include <bsd.port.mk>
