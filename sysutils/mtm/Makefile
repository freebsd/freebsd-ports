# $FreeBSD$

PORTNAME=	mtm
DISTVERSION=	g20180507
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Terminal multiplexer focued on simplicity, compatibility and stability

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/README.rst

USES=		ncurses

USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	deadpixi
GH_TAGNAME=	b861104

PLIST_FILES=	bin/mtm \
		man/man1/mtm.1.gz

MAKE_ARGS+=	LIBS='-lutil -lncursesw'

PORTDATA=	mtm.ti

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${STAGEDIR}${DATADIR}/mtm.ti

.include <bsd.port.mk>
