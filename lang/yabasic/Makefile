# Created by: Frank Gruender <elwood@mc5sys.in-berlin.de>
# $FreeBSD$

PORTNAME=	yabasic
PORTVERSION=	2.768
CATEGORIES=	lang
MASTER_SITES=	http://www.yabasic.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Basic for Unix and Windows

LICENSE=	ART10 GPLv2
LICENSE_COMB=	multi

USES=		bison
GNU_CONFIGURE=	yes
USE_XORG=	x11 ice sm

PORTDOCS=	yabasic.htm
PLIST_FILES=	bin/yabasic man/man1/yabasic.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" && ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		all tests end up with segfault on FreeBSD < 10.x amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DUNIX|@X_CFLAGS@ &|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/Intrinsic\.h/d' ${WRKSRC}/yabasic.h

post-build test:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} check -C ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
