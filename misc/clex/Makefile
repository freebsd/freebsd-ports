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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
