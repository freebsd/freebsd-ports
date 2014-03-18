# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	disktype
PORTVERSION=	9
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Disk formatting type autodetector

USES=		gmake

PLIST_FILES=	bin/disktype
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
.for var in CFLAGS LDFLAGS CC
	@${REINPLACE_CMD} -e 's|^\(${var}\)[ ]*=|\1 ?=|' \
		${WRKSRC}/Makefile
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
