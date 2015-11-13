# Created by: Frank Gruender <elwood@mc5sys.in-berlin.de>
# $FreeBSD$

PORTNAME=	yabasic
PORTVERSION=	2.769
CATEGORIES=	lang
MASTER_SITES=	http://www.yabasic.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Basic for Unix and Windows

LICENSE=	ART10 GPLv2
LICENSE_COMB=	multi

USES=		bison ncurses
GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11

PORTDOCS=	yabasic.htm
PLIST_FILES=	bin/yabasic man/man1/yabasic.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" && ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		all tests end up with segfault on FreeBSD < 10.x amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|= -DUNIX|= @X_CFLAGS@ -DUNIX|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-R$$x_libraries||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/Intrinsic.h/d' ${WRKSRC}/yabasic.h

post-build test:
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} check)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
