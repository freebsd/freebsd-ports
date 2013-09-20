# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	mac-robber
PORTVERSION=	1.02
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	onatan@gmail.com
COMMENT=	Tool for listing Modify, Access, Create timestamps from files

LICENSE=	GPLv2

PLIST_FILES=	bin/mac-robber
PORTDOCS=	CHANGES README

NO_STAGE=	yes
do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o mac-robber mac-robber.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mac-robber ${PREFIX}/bin

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
