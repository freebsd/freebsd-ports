# $FreeBSD$

PORTNAME=	mtm
DISTVERSION=	1.2.0
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Terminal multiplexer focused on simplicity, compatibility and stability

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/README.rst

# NB: ncurses 6.1 is required.
USES=		localbase:ldflags ncurses:port
USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	deadpixi

PLIST_FILES=	bin/mtm \
		man/man1/mtm.1.gz

CFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${NCURSESLIB} -ltinfow

PORTDATA=	mtm.ti

do-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mtm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/mtm.1
	@${MKDIR} ${STAGEDIR}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mtm ${STAGEDIR}${PREFIX}/bin/mtm
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${STAGEDIR}${DATADIR}/mtm.ti

.include <bsd.port.mk>
