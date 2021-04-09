# Created by: Sergei Kolobov <sergei@kolobov.com>

PORTNAME=	qmail-autoresponder
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	gspurki@gmail.com
COMMENT=	Rate-limited autoresponder for qmail

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbg.so:devel/bglibs

USES=		mysql

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/bglibs
LDFLAGS+=	-L${LOCALBASE}/lib/mysql -L${LOCALBASE}/lib/bglibs

PROGS=		qmail-autoresponder qmail-autoresponder-mysql
DOCS=		NEWS README TODO procedure.txt schema.mysql

ALL_TARGET=	${PROGS}

OPTIONS_DEFINE=	DOCS

do-configure:
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"		> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"			> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"		> ${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGS} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qmail-autoresponder.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
