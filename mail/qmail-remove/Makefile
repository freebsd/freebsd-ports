# New ports collection makefile for:	qmail-remove
# Date created:				Wed Sep 24 16:01:34 CEST 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	qmail-remove
PORTVERSION=	0.93
CATEGORIES=	mail
MASTER_SITES=	http://www.linuxmagic.com/opensource/qmail/qmail-remove/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Removes messages from your qmail queue baed on a particular string

DOC_FILES=	INSTALL LICENSE README

do-build:
	@(cd ${WRKSRC} ;\
	${ECHO_MSG} "Compiling ${PORTNAME}:" ; \
	${ECHO_MSG} "${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME}" ;\
	${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
