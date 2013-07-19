# Created by: Patrick Rinke <patrick@rinke-bochum.de>
# $FreeBSD$

PORTNAME=	ucspi-unix
PORTVERSION=	0.36
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix-domain socket client-server command-line tools

LICENSE=	GPLv2

BUILD_DEPENDS=	${BGLIBS_LIB}/libbg.a:${PORTSDIR}/devel/bglibs

BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
CFLAGS+=	-I${BGLIBS_INC}
LDFLAGS+=	-L${BGLIBS_LIB}

PLIST_FILES=	bin/unixcat bin/unixclient bin/unixserver
MAN1=		unixclient.1 unixserver.1
PORTDOCS=	NEWS PROTOCOL README TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch: .SILENT
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS} ${STRIP}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ./installer
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
