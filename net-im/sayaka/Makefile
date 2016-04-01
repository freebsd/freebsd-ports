# $FreeBSD$

PORTNAME=	sayaka
PORTVERSION=	3.1.0
CATEGORIES=	net-im

MAINTAINER=	sue@iwmt.org
COMMENT=	Command-line twitter client for SIXEL-supported terminal

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	curl:ftp/curl \
		img2sixel:graphics/libsixel

USE_GITHUB=	yes
GH_ACCOUNT=	isaki68k

PLIST_FILES=	bin/sayaka bin/cellsize

USE_PHP=	curl filter hash json mbstring pcntl pdo pdo_sqlite sqlite3
WANT_PHP_CLI=	yes

PORTDOCS=	README.md
PORTDATA=	OAuth.php \
		TwistOAuth.php \
		colormap16.png \
		colormap8.png \
		config.php \
		sayaka.php \
		subr.php \
		twitteroauth.php

ALL_TARGET=	cellsize

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@DATADIR@@|${DATADIR}|g ; \
		 s|@@BINDIR@@|${PREFIX}/bin|g' \
		${WRKSRC}/sayaka.sh
	@${REINPLACE_CMD} 's|-O2|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sayaka.sh ${STAGEDIR}${PREFIX}/bin/sayaka
	${INSTALL_PROGRAM} ${WRKSRC}/cellsize ${STAGEDIR}${PREFIX}/bin/cellsize
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${PORTDATA}
		${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
