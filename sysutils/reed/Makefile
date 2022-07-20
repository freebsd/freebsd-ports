PORTNAME=	reed
PORTVERSION=	5.6
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/crees/reed			\
		https://www.bayofrum.net/dist/reed/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Text pager with autoscrolling and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:bzip2

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configures
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ENV+=		INCDIR="${NCURSESINC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fix_bookmarks.sh ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
