PORTNAME=	highlnk
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://perli.net/projekte/highlnk/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to save disk space on hard disks by using hardlinks
WWW=		https://perli.net/projekte/highlnk/

LICENSE=	GPLv2

PLIST_FILES=	bin/highlnk share/man/man1/highlnk.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|linux/limits.h|sys/syslimits.h|' \
		${WRKSRC}/finder.c \
		${WRKSRC}/highlnk.c
	@${REINPLACE_CMD} -e 's|^FLAGS.*|FLAGS = ${CFLAGS}|; s|^\(CC\).*|\1?=gcc|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
