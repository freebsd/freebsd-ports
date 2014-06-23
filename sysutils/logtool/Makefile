# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	logtool
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://xjack.org/logtool/download/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Parse ASCII logfiles into ANSI, CSV, HTML formats

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		CHANGES CREDITS README TODO doc/logtool.txt

do-build:
	cd ${WRKSRC}/src && ${GMAKE} INCLUDES="${CPPFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/logtool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/logtool.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${EXAMPLESDIR}
	@${RM} ${STAGEDIR}${EXAMPLESDIR}/logtool.conf.in
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}/scripts
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif
	@${SED} -e 's!PREFIX!${PREFIX}!' ${.CURDIR}/pkg-message > ${PKGMESSAGE}

.include <bsd.port.mk>
