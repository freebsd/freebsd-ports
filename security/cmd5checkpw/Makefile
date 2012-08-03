# New ports collection makefile for:	cmd5checkpw
# Date created:				8 Sep 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	cmd5checkpw
PORTVERSION=	0.22
CATEGORIES=	security
MASTER_SITES=	http://beautytech.googlecode.com/svn-history/r6/trunk/src/qmail/tar/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Checkpassword compatible authentication program that uses CRAM-MD5

OPTIONS_DEFINE=	DOCS

MAN8=		cmd5checkpw.8

PORTDOCS=	CHANGES CREDITS INSTALL README rfc1321.txt rfc2104.txt
PLIST_FILES=	bin/cmd5checkpw etc/poppasswd.dist

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/poppasswd|${LOCALBASE}/etc/poppasswd|' \
		${WRKSRC}/main.c
	@${REINPLACE_CMD} -e 's|^\(CC\)|#\1|; s|^\(CFLAGS\)|#\1|; \
		s|LD=gcc|LD=$${CC}|; s|LDFLAGS=-g|LDFLAGS=$${CFLAGS} ${LDFLAGS}|;' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cmd5checkpw ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/poppasswd ${PREFIX}/etc/poppasswd.dist
	@${INSTALL_MAN}	${WRKSRC}/cmd5checkpw.8 ${MANPREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.    for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.    endfor
.endif

.include <bsd.port.post.mk>
