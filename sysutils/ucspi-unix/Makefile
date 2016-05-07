# Created by: Patrick Rinke <patrick@rinke-bochum.de>
# $FreeBSD$

PORTNAME=	ucspi-unix
PORTVERSION=	0.36
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix-domain socket client-server command-line tools

LICENSE=	GPLv2

BUILD_DEPENDS=	${BGLIBS_LIB}/libbg.a:devel/bglibs

BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
CFLAGS+=	-I${BGLIBS_INC}
LDFLAGS+=	-L${BGLIBS_LIB}

PLIST_FILES=	bin/unixcat bin/unixclient bin/unixserver \
		man/man1/unixclient.1.gz man/man1/unixserver.1.gz
PORTDOCS=	NEWS PROTOCOL README TODO

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=yes

post-patch: .SILENT
	${ECHO_CMD} "${STAGEDIR}${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS} ${STRIP}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ./installer

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
