# Created by: Jacek Serwatynski <tutus@trynet.eu.org>
# $FreeBSD$

PORTNAME=	ADMsmb
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/groups/ADM
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Security scanner for Samba

USES=		gmake
MAKE_ARGS=	CC="${CC}" FLAGS1="${CFLAGS}"

post-patch:
	@${FIND} ${WRKSRC} -name "*.o" -delete
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ADMsmb ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ADMsmb
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/ADMsmb

.include <bsd.port.mk>
