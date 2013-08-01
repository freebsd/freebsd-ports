# Created by: Otavio Fernandes <otaviof@gmail.com>
# $FreeBSD$

PORTNAME=	wmpop3lb
PORTVERSION=	2.4.2
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	http://lbj.free.fr/wmpop3/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	otaviof@gmail.com
COMMENT=	WindowMaker dock app for multi POP3 accounts mailbox checking

USES=		gmake
USE_XORG=	xext xpm
USE_CSTD=	gnu89

CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/wmpop3lb
PORTDOCS=	CHANGE_LOG COPYING INSTALL README

BUILD_WRKSRC=	${WRKSRC}/wmpop3

post-patch:
	@${REINPLACE_CMD} -e "s,cc ,${CC} ,g" \
			  -e "s,^FLAGS *=.*$$,FLAGS = ${CFLAGS}," \
			  -e "s,/usr/X11R6,${LOCALBASE},g" \
		${BUILD_WRKSRC}/Makefile

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
