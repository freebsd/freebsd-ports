# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	clex
PORTVERSION=	4.6.7
CATEGORIES=	misc
MASTER_SITES=	http://www.clex.sk/download/
DISTNAME=	clex-4.6.patch7

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Command line file manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		ncurses gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/clex bin/cfg-clex bin/kbd-test \
		man/man1/cfg-clex.1.gz \
		man/man1/clex.1.gz \
		man/man1/kbd-test.1.gz

PORTDOCS=	AUTHORS ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e '18s,^,#include <stdio.h>,' \
		${WRKSRC}/src/preview.c

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
