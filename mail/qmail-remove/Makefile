# New ports collection makefile for:	qmail-remove
# Date created:				Wed Sep 24 16:01:34 CEST 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	qmail-remove
PORTVERSION=	0.95
CATEGORIES=	mail
MASTER_SITES=	http://www.linuxmagic.com/opensource/qmail/qmail-remove/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Removes messages from your qmail queue based on a particular string

PLIST_FILES=	sbin/qmail-remove bin/populate.pl
PORTDOCS=	INSTALL LICENSE README

do-build:
	@(cd ${WRKSRC} ;\
	${ECHO_MSG} "Compiling ${PORTNAME}:" ; \
	${ECHO_MSG} "${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME}" ;\
	${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME} )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/populate.pl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
