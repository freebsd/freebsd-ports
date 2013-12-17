# Created by: ijliao
# $FreeBSD$

PORTNAME=	ttyload
PORTVERSION=	0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daveltd.com/src/util/ttyload/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Give a color-coded graph of load averages over time

ALL_TARGET=	default

USE_BZIP2=	yes
PLIST_FILES=	bin/ttyload
MAN1=	ttyload.1

.include <bsd.port.pre.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}/LICENSE
.endif
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
