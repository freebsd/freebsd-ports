# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	cmd5checkpw
PORTVERSION=	0.22
CATEGORIES=	security
MASTER_SITES=	http://beautytech.googlecode.com/svn-history/r6/trunk/src/qmail/tar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkpassword compatible authentication program that uses CRAM-MD5

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES CREDITS INSTALL README rfc1321.txt rfc2104.txt
PLIST_FILES=	bin/cmd5checkpw \
		etc/poppasswd.dist \
		man/man8/cmd5checkpw.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/poppasswd|${LOCALBASE}/etc/poppasswd|' \
		${WRKSRC}/main.c
	@${REINPLACE_CMD} -e 's|^\(CC\)|#\1|; s|^\(CFLAGS\)|#\1|; \
		s|LD=gcc|LD=$${CC}|; s|LDFLAGS=-g|LDFLAGS=$${CFLAGS} ${LDFLAGS}|;' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmd5checkpw ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/poppasswd ${STAGEDIR}${PREFIX}/etc/poppasswd.dist
	${INSTALL_MAN}	${WRKSRC}/cmd5checkpw.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
