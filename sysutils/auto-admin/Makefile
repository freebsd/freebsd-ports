# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	auto-admin
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for automating system management

LICENSE=	BSD

USE_XZ=		yes

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/Common/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/FreeBSD/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/Data/* ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/Doc/auto-admin.man \
		${STAGEDIR}${MANPREFIX}/man/man1/auto-admin.1
	for name in ${WRKSRC}/Scripts/Common/* ${WRKSRC}/Scripts/FreeBSD/*; do \
		${INSTALL_MAN} ${WRKSRC}/Doc/auto-admin.man \
			${STAGEDIR}${MANPREFIX}/man/man1/`basename $${name}`.1; \
	done

.include <bsd.port.mk>
