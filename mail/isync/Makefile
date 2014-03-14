# Created by: eivind
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	1.1.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_BDB=	46+

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${OPENSSLINC}
LDFLAGS+=	-L${BDB_LIB_DIR} -L${OPENSSLLIB} -lssl -lcrypto

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ansi||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
