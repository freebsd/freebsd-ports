# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	clex
PORTVERSION=	4.6.6
CATEGORIES=	misc
MASTER_SITES=	http://www.clex.sk/download/
DISTNAME=	clex-4.6.patch6

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A command line file manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		ncurses
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/clex bin/cfg-clex bin/kbd-test
PORTDOCS=	AUTHORS ChangeLog README
MAN1=		clex.1 cfg-clex.1 kbd-test.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '18s,^,#include <stdio.h>,' \
		${WRKSRC}/src/preview.c

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
