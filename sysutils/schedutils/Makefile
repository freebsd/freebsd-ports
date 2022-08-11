PORTNAME=	schedutils
PORTVERSION=	0.7.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of realtime scheduling tools

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e '/ctype.h/d' ${WRKSRC}/isnumber.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/getsched ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/resched ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sched ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sched.8 ${STAGEDIR}${PREFIX}/man/man8
	${LN} -sf sched.8.gz ${STAGEDIR}${PREFIX}/man/man8/resched.8.gz

.include <bsd.port.mk>
