# New ports collection makefile for:	bcrypt
# Date created:				11 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bcrypt
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A cross-plattform blowfish encryption utility

ALL_TARGET=	${PORTNAME}

LDFLAGS+=	-lz
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

PORTDOCS=	README
MAN1=		bcrypt.1
PLIST_FILES=	bin/bcrypt

post-patch:
	@${REINPLACE_CMD} -E 's/^(CC|CFLAGS|LDFLAGS|PREFIX)\ /\1?/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
