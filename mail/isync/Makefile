# New ports collection makefile for:	isync
# Date created:				2000-12-23
# Whom:					eivind
#
# $FreeBSD$
#

PORTNAME=	isync
PORTVERSION=	1.0.4
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_BDB=	42+
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		isync.1 mbsync.1 mdconvert.1
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PLIST_FILES=	bin/get-cert bin/isync bin/mbsync bin/mdconvert

CPPFLAGS=	-I${BDB_INCLUDE_DIR} -I${OPENSSLINC}
LDFLAGS=	-L${BDB_LIB_DIR} -L${OPENSSLLIB} -lssl -lcrypto

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
