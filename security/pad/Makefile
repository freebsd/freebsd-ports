# Created by: trevor
# $FreeBSD$

PORTNAME=	pad
PORTVERSION=	1.0.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Command-line utility to encrypt files

BROKEN=		unfetchable

USES=		tar:tgz ssl
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pad man/man1/pad.1.gz
PORTDOCS=	COPYING README ChangeLog

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s|\(-lcrypto\)|${LDFLAGS} \1|g" \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pad ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pad.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
