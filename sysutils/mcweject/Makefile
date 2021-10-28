PORTNAME=	mcweject
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Removable media eject

LICENSE=	BSD3CLAUSE

SUB_FILES=	pkg-message

CONFLICTS=	eject

USES=		tar:xz

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/eject.allow ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/eject ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/eject.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
