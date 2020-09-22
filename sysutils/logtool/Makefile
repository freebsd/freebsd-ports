# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	logtool
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://xjack.org/logtool/download/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Parse ASCII logfiles into ANSI, CSV, HTML formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		CHANGES CREDITS README TODO doc/logtool.txt

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC}/src && ${MAKE_CMD} INCLUDES="${CPPFLAGS}")

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/logtool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/logtool.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${EXAMPLESDIR}
	@${RM} ${STAGEDIR}${EXAMPLESDIR}/logtool.conf.in
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}/scripts
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	@${SED} -e 's!PREFIX!${PREFIX}!' ${.CURDIR}/pkg-message > ${PKGMESSAGE}

.include <bsd.port.mk>
