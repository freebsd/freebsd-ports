PORTNAME=	bcrypt
DISTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cross-platform blowfish encryption utility
WWW=		https://bcrypt.sourceforge.net/

ALL_TARGET=	${PORTNAME}

LDFLAGS+=	-lz

PLIST_FILES=	bin/bcrypt \
		share/man/man1/bcrypt.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Hasn't seen updates in 15 years, insecure Blowfish ECB mode, unauthenticated encryption
EXPIRATION_DATE=2024-07-02

post-patch:
	@${REINPLACE_CMD} -E 's/^(CC|CFLAGS|LDFLAGS|PREFIX)\ /\1?/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
