# New ports collection makefile for:	cmd5checkpw
# Date created:				8 Sep 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	cmd5checkpw
PORTVERSION=	0.22
CATEGORIES=	security
MASTER_SITES=	http://members.elysium.pl/brush/cmd5checkpw/dist/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Checkpassword compatible authentication program that uses CRAM-MD5

MAN8=		cmd5checkpw.8

DOCS_FILES=	CHANGES CREDITS INSTALL README rfc1321.txt rfc2104.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/poppasswd|${LOCALBASE}/etc/poppasswd|' \
		${WRKSRC}/main.c
	@${REINPLACE_CMD} -e 's|^\(CC\)|#\1|; s|^\(CFLAGS\)|#\1|; \
		s|LD=gcc|LD=$${CC}|; s|LDFLAGS=-g|LDFLAGS=$${CFLAGS} ${LDFLAGS}|;' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cmd5checkpw ${LOCALBASE}/bin
	@${INSTALL_DATA} ${WRKSRC}/poppasswd ${LOCALBASE}/etc/poppasswd.dist
	@${INSTALL_MAN}	${WRKSRC}/cmd5checkpw.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.    for f in ${DOCS_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.    endfor
.endif

.include <bsd.port.mk>
