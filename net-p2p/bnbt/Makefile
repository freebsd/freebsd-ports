# New ports collection makefile for:	bnbt
# Date created:				Jan 31 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	bnbt
PORTVERSION=	8.1b3
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bnbt
DISTNAME=	bnbt81b-3-sf

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A C++ BitTorrent Tracker

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_GMAKE=	yes

SUB_FILES=	pkg-message
USE_RC_SUBR=	bnbt.sh

PORTDOCS=	footer.html header.html lesser.txt readme.txt users.txt

.if defined(WITH_MYSQL)
ALL_TARGET=	bnbtmysql
PKGNAMESUFFIX=	-mysql
USE_MYSQL=	yes
.else
ALL_TARGET=	bnbt
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS} -I${PREFIX}/include| ; \
		s|LFLAGS =|LFLAGS = -L${PREFIX}/lib/mysql|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|\([a-z]*\.bnbt\)|${PREFIX}/etc/${PORTNAME}/\1|' \
		${WRKSRC}/config.cpp
	@${REINPLACE_CMD} -e 's|bnbt.cfg|${PREFIX}/etc/${PORTNAME}/bnbt.cfg|' \
		${WRKSRC}/config.h ${WRKSRC}/config.cpp ${WRKSRC}/tracker.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ALL_TARGET} ${PREFIX}/bin/bnbt
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/$i ${DOCSDIR}
.endfor

post-install:
	@${MKDIR} /var/log/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
