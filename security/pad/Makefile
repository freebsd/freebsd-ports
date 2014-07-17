# Created by: trevor
# $FreeBSD$

PORTNAME=	pad
PORTVERSION=	1.0.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jharris@widomaker.com
COMMENT=	Command-line utility to encrypt files

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

PLIST_FILES=	bin/pad man/man1/pad.1.gz
PORTDOCS=	COPYING README ChangeLog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pad ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pad.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
