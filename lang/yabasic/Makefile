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

MAN1=		yabasic.1
PORTDOCS=	yabasic.htm
PLIST_FILES=	bin/yabasic

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|= -DUNIX|= @X_CFLAGS@ -DUNIX|g" ${WRKSRC}/Makefile.in

post-build test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
