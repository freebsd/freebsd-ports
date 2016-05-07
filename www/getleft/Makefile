# Created by: alepulver
# $FreeBSD$

PORTNAME=	getleft
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	www ftp
MASTER_SITES=	SF/${PORTNAME}down/${PORTNAME}-Stable/${PORTVERSION}
DISTNAME=	Getleft-v${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Web site downloader

RUN_DEPENDS=	${LOCALBASE}/lib/Tktable2.10/libTktable2.10.so:x11-toolkits/tktable \
		${LOCALBASE}/lib/libttkstub.a:x11-toolkits/tile

USES=		tk
PORTSCOUT=	ignore:1

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${WISH} Getleft.tcl "$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Getleft.tcl ${STAGEDIR}${DATADIR}
.for dir in Languages doc scripts images
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
