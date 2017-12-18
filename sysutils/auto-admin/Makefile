# $FreeBSD$

PORTNAME=	auto-admin
DISTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable tools for automating systems management

LICENSE=	BSD2CLAUSE

USES=		tar:xz

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Common/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/Data/* ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/Doc/auto-admin.man \
		${STAGEDIR}${MANPREFIX}/man/man1/auto-admin.1
	for name in ${WRKSRC}/Common/Scripts/* ${WRKSRC}/FreeBSD/Scripts/*; do \
		${INSTALL_MAN} ${WRKSRC}/Doc/auto-admin.man \
			${STAGEDIR}${MANPREFIX}/man/man1/`basename $${name}`.1; \
	done

.include <bsd.port.mk>
