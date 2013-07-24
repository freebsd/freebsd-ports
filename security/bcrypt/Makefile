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
MAN1=		bcrypt.1
PLIST_FILES=	bin/bcrypt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E 's/^(CC|CFLAGS|LDFLAGS|PREFIX)\ /\1?/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
