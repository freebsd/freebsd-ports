# Created by: eivind
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	1.0.6
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_BDB=	42+

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PLIST_FILES=	bin/get-cert bin/isync bin/mbsync bin/mdconvert \
		man/man1/isync.1.gz man/man1/mbsync.1.gz man/man1/mdconvert.1.gz

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${OPENSSLINC}
LDFLAGS+=	-L${BDB_LIB_DIR} -L${OPENSSLLIB} -lssl -lcrypto

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
