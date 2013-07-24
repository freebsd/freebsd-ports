# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	highlnk
DISTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://perli.net/projekte/highlnk/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to save disk space on hard disks by using hardlinks

LICENSE=	GPLv2

PLIST_FILES=	bin/highlnk
PORTDOCS=	README
MAN1=		highlnk.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|linux/limits.h|sys/syslimits.h|' \
		${WRKSRC}/finder.c \
		${WRKSRC}/highlnk.c
	@${REINPLACE_CMD} -e 's|^FLAGS.*|FLAGS = ${CFLAGS}|; s|^\(CC\).*|\1?=gcc|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
