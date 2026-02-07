PORTNAME=	spacenavd
DISTVERSION=	r${GIT_SRC_DATE}
CATEGORIES=	misc x11-drivers
PKGNAMESUFFIX=	-devel

MAINTAINER=	mr@freebsd.org
COMMENT=	Daemon for Spacenav driver
WWW=	http://spacenav.sourceforge.net/index.html

LICENSE=	GPLv3+

USES=		gmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FreeSpacenav
GH_PROJECT=	spacenavd
GH_TAGNAME=	${GIT_SRC_HASH}
USE_RC_SUBR=	spacenavd
USE_XORG=	x11 xext xi xtst
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

.include	"Makefile.git_rev"

post-configure:
		@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/src/config.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/example-spnavrc ${STAGEDIR}${PREFIX}/etc/spnavrc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spacenavd

.include <bsd.port.mk>
