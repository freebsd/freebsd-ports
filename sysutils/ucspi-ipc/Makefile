# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	ucspi-ipc
PORTVERSION=	0.67
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/ucspi-ipc/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	UCSPI tools for building local-domain client-server applications

USES=		perl5

DISABLE_SIZE=	yes

DOCS=		CHANGES

WRKSRC=		${WRKDIR}/host/superscript.com/net/${DISTNAME}

.include <bsd.port.options.mk>

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-ld

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} package/compile

do-install:
.for x in ipccat ipcconnect ipcdo ipcrun
	${INSTALL_SCRIPT} ${WRKSRC}/command/${x} ${STAGEDIR}${PREFIX}/bin
.endfor
.for x in ipcclient ipccommand ipcconnect-io ipcexec ipcexec-config \
	ipcexecrules ipcexecrulescheck ipcperl ipcrules ipcrulescheck ipcserver
	${INSTALL_PROGRAM} ${WRKSRC}/command/${x} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
