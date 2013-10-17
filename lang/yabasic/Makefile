# Created by: Frank Gruender
# $FreeBSD$

PORTNAME=	yabasic
PORTVERSION=	2.763
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.yabasic.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Basic for Unix and Windows

USE_XORG=	x11 ice sm xt
USES=		bison
GNU_CONFIGURE=	yes

PORTDOCS=	yabasic.htm
PLIST_FILES=	bin/yabasic man/man1/yabasic.1.gz

.include <bsd.port.options.mk>

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
