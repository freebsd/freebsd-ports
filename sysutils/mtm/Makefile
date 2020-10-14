# $FreeBSD$

PORTNAME=	mtm
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Terminal multiplexer focused on simplicity, compatibility and stability

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/README.rst

# NB: ncurses 6.1 is required.
USES=		localbase:ldflags

USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	deadpixi

PLIST_FILES=	bin/mtm \
		share/man/man1/mtm.1.gz

CFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${NCURSESLIB} -ltinfow

PORTDATA=	mtm.ti

do-install:
	${INSTALL_MAN} ${WRKSRC}/mtm.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1/mtm.1
	@${MKDIR} ${STAGEDIR}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mtm ${STAGEDIR}${PREFIX}/bin/mtm
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${STAGEDIR}${DATADIR}/mtm.ti

.include <bsd.port.options.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1300079
USES+=		ncurses:base
.else
USES+=		ncurses:port
.endif

.include <bsd.port.mk>
