# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	bcrypt
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cross-platform blowfish encryption utility

ALL_TARGET=	${PORTNAME}

LDFLAGS+=	-lz

PORTDOCS=	README
PLIST_FILES=	bin/bcrypt man/man1/bcrypt.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E 's/^(CC|CFLAGS|LDFLAGS|PREFIX)\ /\1?/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
