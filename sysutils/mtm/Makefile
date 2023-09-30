PORTNAME=	mtm
DISTVERSION=	1.2.1
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Terminal multiplexer focused on simplicity, compatibility and stability
WWW=		https://github.com/deadpixi/mtm

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/README.rst

# NB: ncurses 6.1 is required.
USES=		localbase ncurses:base

USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	deadpixi

CFLAGS+=	-I${NCURSESINC} ${CPPFLAGS}
LIBS+=		-L${NCURSESLIB} -lncurses -lutil

BINARY_ALIAS=	strip=true

PLIST_FILES=	bin/mtm \
		share/man/man1/mtm.1.gz
PORTDATA=	mtm.ti

do-install:
	${INSTALL_MAN} ${WRKSRC}/mtm.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1/mtm.1
	@${MKDIR} ${STAGEDIR}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mtm ${STAGEDIR}${PREFIX}/bin/mtm
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${STAGEDIR}${DATADIR}/mtm.ti

.include <bsd.port.mk>
