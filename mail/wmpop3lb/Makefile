# New ports collection makefile for:	wmpop3lb
# Date created:		2007-07-06
# Whom:			Otavio Fernandes <otaviof@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wmpop3lb
PORTVERSION=	2.4.2
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	http://lbj.free.fr/wmpop3/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	otaviof@gmail.com
COMMENT=	A WindowMaker dock app for multi POP3 accounts mailbox checking

USE_GMAKE=	yes
USE_XORG=	xext xpm

CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/wmpop3lb
PORTDOCS=	CHANGE_LOG COPYING INSTALL README

WRKSRC_BUILD=	${WRKSRC}/wmpop3

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,cc ,${CC} ,g" \
			  -e "s,^FLAGS *=.*$$,FLAGS = ${CFLAGS}," \
			  -e "s,/usr/X11R6,${LOCALBASE},g" \
		${WRKSRC_BUILD}/Makefile

do-build:
	@cd ${WRKSRC_BUILD} && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC_BUILD}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
