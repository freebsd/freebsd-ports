PORTNAME=	qmail-qfilter
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end for qmail-queue to run messages through filters
WWW=		https://untroubled.org/qmail-qfilter/

LICENSE=	GPLv2

LIB_DEPENDS=	libbg.so:devel/bglibs

BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

DOCS=		NEWS README TODO

OPTIONS_DEFINE=	DOCS EXAMPLES

do-configure:
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/share/man" > ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} samples/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
