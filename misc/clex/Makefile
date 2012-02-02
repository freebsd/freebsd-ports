# New ports collection makefile for:	CLEX File Manager
# Date created:				Tue Oct 30, 2002
# Whom:			Michael L. Hostbaek <mich@freebsdcluster.org>
#
# $FreeBSD$
#

PORTNAME=	clex
PORTVERSION=	4.6.4
CATEGORIES=	misc
MASTER_SITES=	http://www.clex.sk/download/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A command line file manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NCURSES=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/clex bin/cfg-clex bin/kbd-test
PORTDOCS=	AUTHORS ChangeLog README
MAN1=		clex.1 cfg-clex.1 kbd-test.1

post-patch:
	@${REINPLACE_CMD} -e '18s,^,#include <stdio.h>,' \
		${WRKSRC}/src/preview.c

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
