# New ports collection makefile for:	bnbt
# Date created:				Jan 31 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	bnbt
PORTVERSION=	8.1b3
CATEGORIES=	net
MASTER_SITES=	http://bnbt.go-dedicated.com/
DISTNAME=	bnbt81b-3

MAINTAINER=	flz@xbsd.org
COMMENT=	A C++ BitTorrent Tracker

BROKEN=		Unfetchable

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	yes

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

PLIST_FILES=	bin/bnbt
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

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/bnbt.sh > ${WRKDIR}/bnbt.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/pkg-message.in > ${WRKDIR}/pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ALL_TARGET} ${PREFIX}/bin/bnbt
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/$i ${DOCSDIR}
.endfor

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/bnbt.sh ${PREFIX}/etc/rc.d/bnbt.sh
	@${ECHO_CMD} "etc/rc.d/bnbt.sh" >> ${TMPPLIST}
	@${MKDIR} /var/log/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
