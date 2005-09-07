# New ports collection makefile for:	ucspi-unix
# Date created:         23.Sep.2003
# Whom:                 patrick@rinke-bochum.de
#
# $FreeBSD$
#

PORTNAME=	ucspi-unix
PORTVERSION=	0.36
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	UNIX-domain socket client-server command-line tools

BUILD_DEPENDS=	${BGLIBS_LIB}/libbg.a:${PORTSDIR}/devel/bglibs

BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
CFLAGS+=	-I${BGLIBS_INC}
LDFLAGS+=	-s -L${BGLIBS_LIB}

PLIST_FILES=	bin/unixcat bin/unixclient bin/unixserver
MAN1=		unixclient.1 unixserver.1
PORTDOCS=	NEWS PROTOCOL README TODO

post-patch:
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ./installer

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
