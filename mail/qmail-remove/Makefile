# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	qmail-remove
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.linuxmagic.com/opensource/qmail/qmail-remove/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Removes messages from your qmail queue based on a particular string

PLIST_FILES=	sbin/qmail-remove bin/populate-qmail-queue.pl
PORTDOCS=	INSTALL LICENSE README

USES=		shebangfix
SHEBANG_FILES=	populate.pl

do-build:
	@(cd ${WRKSRC} ;\
	${ECHO_MSG} "Compiling ${PORTNAME}:" ; \
	${ECHO_MSG} "${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME}" ;\
	${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME} )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/populate.pl \
	${STAGEDIR}${PREFIX}/bin/populate-qmail-queue.pl
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
