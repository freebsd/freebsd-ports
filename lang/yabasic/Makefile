# Created by: Frank Gruender
# $FreeBSD$

PORTNAME=	yabasic
PORTVERSION=	2.767
CATEGORIES=	lang
MASTER_SITES=	http://www.yabasic.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Basic for Unix and Windows

USE_XORG=	x11 ice sm xt
USES=		bison
GNU_CONFIGURE=	yes

PORTDOCS=	yabasic.htm
PLIST_FILES=	bin/yabasic man/man1/yabasic.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" && ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		all tests end up with segfault on FreeBSD < 10.x amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|= -DUNIX|= @X_CFLAGS@ -DUNIX|g" ${WRKSRC}/Makefile.in

post-build test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
